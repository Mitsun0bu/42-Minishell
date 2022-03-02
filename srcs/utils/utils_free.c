/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:48:19 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/02 19:12:08 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "main.h"

void	ft_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	free_struct(t_input *input)
{
	ft_free(input->cmd_line);
	free_double(input->cmd_tab);
	free(input->last_output_redir_tab);
	free_quad(input->redir_tab);
	free_triple(input->cmd_exec_tab);
	free_double(input->paths_tab);
	// reflechir au free des tableaux de fd qui ne seront pas malloc si il y a une seule commande a executer
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
