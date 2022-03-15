/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:38:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/15 18:37:29 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_input_struct(t_input *input)
{
	ft_free(input->cmd_line);
	free_double(input->cmd_tab);
	ft_free(input->last_output_redir_tab);
	free_quad(input->redir_tab);
	free_triple(input->cmd_exec_tab);
	free_double(input->paths_tab);
	if (input->n_cmd > 1)
		ft_free(input->process);
}

void	free_env_struct(t_input *input)
{
	int	i;

	i = -1;
	while (++i < input->n_env)
	{
		ft_free(input->env_tab[i].key);
		ft_free(input->env_tab[i].value);
	}
	ft_free(input->env_tab);
}
