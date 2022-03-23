/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_garbage_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:24:45 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/23 15:26:11 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_add_garbage_front(t_garbage_lst **garbage, t_garbage_lst *new_garbage)
{
	if (!new_garbage)
		return ;
	new_garbage->next = *garbage;
	(*garbage)->previous = new_garbage;
	*garbage = new_garbage;
}