/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_garbage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:15:45 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/05 10:06:06 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	clear_all_garbage(t_garbage_lst **garbage)
{
	t_garbage_lst	*next;

	if (!*garbage)
		return ;
	while (*garbage)
	{
		next = (*garbage)->next;
		free((*garbage)->ptr);
		if (!next)
		{
			free(*garbage);
			break ;
		}
		*garbage = next;
		// if ((*garbage)->previous)
		// 	free((*garbage)->previous);
	}
	*garbage = NULL;
}

void	clear_one_garbage_type(t_garbage_lst **garbage, int type)
{
	t_garbage_lst	*temp;
	t_garbage_lst	*prev;

	while (count_garbage_type(garbage, type) != 0)
	{
		temp = *garbage;
		if (temp && temp->type == type)
		{
			*garbage = temp->next;
			free(temp->ptr);
			free(temp);
			(*garbage)->previous = NULL;
			return ;
		}
		while (temp && temp->type != type)
		{
			prev = temp;
			temp = temp->next;
		}
		if (!temp)
			return ;
		prev->next = temp->next;
		free(temp->ptr);
		free(temp);
	}
}

int	count_garbage_type(t_garbage_lst **garbage, int type)
{
	int				count;
	t_garbage_lst	*start;

	count = 0;
	start = *garbage;
	while (*garbage)
	{
		if ((*garbage)->type == type)
			count ++;
		*garbage = (*garbage)->next;
	}
	*garbage = start;
	return (count);
}
