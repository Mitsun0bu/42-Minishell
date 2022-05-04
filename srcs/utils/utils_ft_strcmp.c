/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_strcmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:06:12 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/04 19:03:58 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = -1;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (FAILED);
	while (s1[++i])
		if (s1[i] != s2[i])
			return (FAILED);
	return (SUCCESS);
}
