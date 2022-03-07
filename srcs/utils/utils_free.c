/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:48:19 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/07 11:46:33 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	free_double(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_free(array[i]);
		i++;
	}
	ft_free(array);
}

void	free_quad(char ****array)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (array[++i])
	{
		j = -1;
		while (array[i][++j])
		{
			k = -1;
			while (array[i][j][++k])
				ft_free(array[i][j][k]);
			ft_free(array[i][j]);
		}
		ft_free(array[i]);
	}
	ft_free(array);
}

void	free_triple(char ***array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			ft_free(array[i][j]);
			j++;
		}
		ft_free(array[i]);
		i++;
	}
	ft_free(array);
}
