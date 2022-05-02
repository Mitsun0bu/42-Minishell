/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_gb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:15:45 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/05 10:06:06 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// static int	count_gb_type(t_gb_lst **gb, int type);

// void	clear_all_gb(t_gb_lst **gb)
// {
// 	t_gb_lst	*next;

// 	if (!*gb)
// 		return ;
// 	while (*gb)
// 	{
// 		next = (*gb)->next;
// 		free((*gb)->ptr);
// 		if (!next)
// 		{
// 			free(*gb);
// 			break ;
// 		}
// 		*gb = next;
// 	}
// 	*gb = NULL;
// }

void	clear_all_gb(t_gb_lst **gb)
{
	t_gb_lst	*to_clear;

	if (!*gb)
		return ;
	while ((*gb)->previous != NULL)
		*gb = (*gb)->previous;
	while (*gb)
	{
		to_clear = *gb;
		*gb = to_clear->next;
		free(to_clear->ptr);
		free(to_clear);
		(*gb)->previous = NULL;
		if (!(*gb)->next)
		{
			free(*gb);
			break ;
		}
	}
}

void	clear_one_gb_type(t_gb_lst **gb, int type)
{
	t_gb_lst	*to_clear;

	while ((*gb)->previous != NULL)
		*gb = (*gb)->previous;
	while (*gb)
	{
		to_clear = *gb;
		*gb = to_clear->next;
		if (to_clear->type == type)
		{
			(*gb)->previous = to_clear->previous;
			to_clear->previous->next = *gb;
			free(to_clear->ptr);
			free(to_clear);
		}
		if (!(*gb)->next)
			break ;
	}
}

// void	clear_one_gb_type(t_gb_lst **gb, int type)
// {
// 	t_gb_lst	*temp;
// 	t_gb_lst	*prev;

// 	while ((*gb)->previous != NULL)
// 		*gb = (*gb)->previous;
// 	while (count_gb_type(gb, type) != 0)
// 	{
// 		temp = *gb;
// 		if (temp && temp->type == type)
// 		{
// 			*gb = temp->next;
// 			free(temp->ptr);
// 			free(temp);
// 			(*gb)->previous = NULL;
// 			return ;
// 		}
// 		while (temp && temp->type != type)
// 		{
// 			prev = temp;
// 			temp = temp->next;
// 		}
// 		if (!temp)
// 			return ;
// 		prev->next = temp->next;
// 		free(temp->ptr);
// 		free(temp);
// 	}
// }

// static int	count_gb_type(t_gb_lst **gb, int type)
// {
// 	int			count;
// 	t_gb_lst	*start;

// 	count = 0;
// 	start = *gb;
// 	while (*gb)
// 	{
// 		if ((*gb)->type == type)
// 			count ++;
// 		*gb = (*gb)->next;
// 	}
// 	*gb = start;
// 	return (count);
// }
