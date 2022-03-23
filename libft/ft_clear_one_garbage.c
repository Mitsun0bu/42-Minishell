/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_one_garbage.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:25:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/23 15:26:00 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clear_one_garbage_type(t_garbage_lst **garbage, int type)
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