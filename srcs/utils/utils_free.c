/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:48:19 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/15 15:55:49 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "main.h"

void	free_struct(t_input *input)
{
	free(input->cmd_line);
	free_double(input->cmd_tab);
	free_quad(input->redir_tab);
	free_triple(input->cmd_exec_tab);
}

void	free_double(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
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
			{
				free(array[i][j][k]);
			}
			free(array[i][j]);
		}
		free(array[i]);
	}
	free(array);
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
			free(array[i][j]);
			j++;
		}
		free(array[i]);
		i++;
	}
	free(array);
}
