/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_garbage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:24:45 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/25 10:19:07 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_add_garbage(t_garbage_lst **garbage, void *ptr)
{
	if (!(*garbage))
		*garbage = ft_create_new_garbage(ptr);
	else
		ft_add_garbage_front(garbage, ft_create_new_garbage(ptr));
}