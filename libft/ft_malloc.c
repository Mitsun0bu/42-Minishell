/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:17:18 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/20 10:03:38 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(t_input *input, size_t size, size_t count)
{
	void	*ptr;

	ptr = malloc(size * count);
	if (!ptr)
		exit_err(input, -1, "error", ": memory allocation failed");
	add_gb(&input->gb, ptr);
	return (ptr);
}
