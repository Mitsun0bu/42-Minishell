/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:33:55 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/12 15:54:51 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../incs/utils.h"

char	*ft_substr(t_input *input, char *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		substr = ft_malloc(input, sizeof(char), (ft_strlen(s) + 1));
	else
		substr = ft_malloc(input, sizeof(char), (len + 1));
	i = 0;
	if (start >= ft_strlen(s))
	{
		substr[i] = '\0';
		return (substr);
	}
	while (s[start] && i < len)
	{
		substr[i] = s[start];
		start ++;
		i ++;
	}
	substr[i] = '\0';
	return (substr);
}
