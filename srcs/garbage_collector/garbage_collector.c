/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:47:32 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/22 19:32:51 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_garbage_lst	*create_new_garbage(void *ptr, int type)
{
	t_garbage_lst	*new_garbage;

	new_garbage->ptr = ptr;
	new_garbage->type = type;
	new_garbage->next = NULL;
	new_garbage->previous = NULL;
	return (new_garbage);
}

void	add_garbage_front(t_garbage_lst **garbage, t_garbage_lst *new_garbage)
{
	if (!new_garbage)
		return ;
	new_garbage->next = *garbage;
	(*garbage)->previous = new_garbage;
	*garbage = new_garbage;
}

void	clear_all_garbage(t_garbage_lst **garbage)
{
	t_garbage_lst	*current;
	t_garbage_lst	*next;

	if (!*garbage)
		return ;
	current = *garbage;
	while (current)
	{
		next = current->next;
		if ((*garbage)->ptr)
			free((*garbage)->ptr);
		free(*garbage);
		current = next;
	}
	*garbage = NULL;
}

void	clear_one_garbage_type(t_garbage_lst **garbage, int type)
{
	t_garbage_lst	*current;
	t_garbage_lst	*next;

	if (!*garbage)
		return ;
	current = *garbage;
	while (current)
	{
		next = current->next;
		if (current->type == type && (*garbage)->ptr)
		{
			current->previous->next = next;
			free((*garbage)->ptr);
			free(*garbage);
		}
		current = next;
	}
	*garbage = NULL;
}
