/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:17:18 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/25 11:40:41 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(t_input *input, size_t size, size_t count)
{
	void	*ptr;

	ptr = malloc(size * count);
	if (!ptr)
	{
		perror("malloc");
		exit (0);
	}
	ft_add_garbage(&input->garbage, ptr);
	return (ptr);
}