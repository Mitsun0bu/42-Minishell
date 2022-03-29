/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_garbage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:24:45 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/29 09:48:23 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	add_garbage(t_garbage_lst **garbage, void *ptr)
{
	if (!(*garbage))
		*garbage = create_new_garbage(ptr);
	else
		add_garbage_front(garbage, create_new_garbage(ptr));
}

void	add_garbage_front(t_garbage_lst **garbage, t_garbage_lst *new_garbage)
{
	new_garbage->next = *garbage;
	(*garbage)->previous = new_garbage;
	*garbage = new_garbage;
}

t_garbage_lst	*create_new_garbage(void *ptr)
{
	static int		i = 0;
	t_garbage_lst	*new_garbage;

	new_garbage = malloc(sizeof(t_garbage_lst));
	if (!new_garbage)
		return (NULL);
	new_garbage->index = i++;
	new_garbage->ptr = ptr;
	new_garbage->type = 0;
	new_garbage->next = NULL;
	new_garbage->previous = NULL;
	return (new_garbage);
}
