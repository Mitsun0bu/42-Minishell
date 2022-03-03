/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:12:43 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/03 10:31:25 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "main.h"

void	skip_quotes(char *str, int *i)
{
	char	c;

	c = str[*i];
	(*i)++;
	while (str[*i] && str[*i] != c)
	{
		(*i)++;
	}
}

void	*safe_malloc(size_t size, size_t count)
{
	void	*result;

	result = malloc(size * count);
	if (!result)
	{
		perror("malloc");
		exit (0);
	}
	return (result);
}
