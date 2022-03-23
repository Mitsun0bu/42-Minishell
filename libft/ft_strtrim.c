/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:35:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/23 16:46:09 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(t_input *input, char *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	trimmed = 0;
	if (s1 != 0 && set != 0)
	{
		start = 0;
		end = ft_strlen(s1);
		while (s1[start] && ft_strchr(set, s1[start]) != NULL)
			start ++;
		while (s1[end - 1] && ft_strchr(set, s1[end - 1]) != NULL
			&& end > start)
			end --;
		trimmed = ft_malloc (input, sizeof(char), end - start + 1);
		ft_strlcpy(trimmed, &s1[start], end - start + 1);
	}
	return (trimmed);
}
