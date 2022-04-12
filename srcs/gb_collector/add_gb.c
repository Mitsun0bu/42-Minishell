/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_gb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:24:45 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/29 09:48:23 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	add_gb(t_gb_lst **gb, void *ptr)
{
	if (!(*gb))
		*gb = create_new_gb(ptr);
	else
		add_gb_front(gb, create_new_gb(ptr));
}

void	add_gb_front(t_gb_lst **gb, t_gb_lst *new_gb)
{
	new_gb->next = *gb;
	(*gb)->previous = new_gb;
	*gb = new_gb;
}

t_gb_lst	*create_new_gb(void *ptr)
{
	static int		i = 0;
	t_gb_lst		*new_gb;

	new_gb = malloc(sizeof(t_gb_lst));
	if (!new_gb)
		return (NULL);
	new_gb->index = i++;
	new_gb->ptr = ptr;
	new_gb->type = 0;
	new_gb->next = NULL;
	new_gb->previous = NULL;
	return (new_gb);
}
