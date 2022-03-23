/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_all_garbage.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:25:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/23 15:25:34 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clear_all_garbage(t_garbage_lst **garbage)
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