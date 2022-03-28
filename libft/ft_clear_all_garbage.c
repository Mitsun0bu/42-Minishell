/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_all_garbage.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:25:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/28 10:37:18 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clear_all_garbage(t_garbage_lst **garbage)
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
			break;
		}
		*garbage = next;
		if ((*garbage)->previous)
			free((*garbage)->previous);
	}
	*garbage = NULL;
}