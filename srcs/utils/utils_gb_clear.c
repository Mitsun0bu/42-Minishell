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

void	clear_all_gb(t_gb_lst **gb)
{
	t_gb_lst	*to_clear;

	if (!*gb)
		return ;
	while ((*gb)->previous != NULL)
		*gb = (*gb)->previous;
	int i = 0;
	while (*gb)
	{
		to_clear = *gb;
		*gb = to_clear->next;
		free(to_clear->ptr);
		free(to_clear);
		i ++;
		(*gb)->previous = NULL;
		if (!(*gb)->next)
		{
			free((*gb)->ptr);
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
