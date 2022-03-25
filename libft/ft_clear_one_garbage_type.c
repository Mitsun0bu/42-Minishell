/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_one_garbage_type.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:25:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/25 16:29:55 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clear_one_garbage_type(t_garbage_lst **garbage, int type)
{
	t_garbage_lst	*start;
	t_garbage_lst	*next;

	if (!*garbage)
		return ;
	start = *garbage;
	while (*garbage)
	{
		next = (*garbage)->next;
		if ((*garbage)->type == type)
		{
			free((*garbage)->ptr);
			(*garbage)->ptr = NULL;
		}
		// if (!next)
		// 	break;
		*garbage = next;
	}
	*garbage = start;
}