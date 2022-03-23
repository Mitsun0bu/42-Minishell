/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:35:30 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/23 15:42:40 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(t_input *input, size_t size, size_t count)
{
	void	*result;

	result = ft_malloc(input, size, count);
	ft_bzero(result, (size * count));
	return (result);
}
