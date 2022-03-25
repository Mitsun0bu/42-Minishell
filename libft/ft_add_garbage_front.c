/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_front_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:00:41 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/25 10:15:33 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_add_garbage_front(t_garbage_lst **garbage, t_garbage_lst *new_garbage)
{
	new_garbage->next = *garbage;
	(*garbage)->previous = new_garbage;
	*garbage = new_garbage;
}