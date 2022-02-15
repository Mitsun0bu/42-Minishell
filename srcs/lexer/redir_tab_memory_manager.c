/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_tab_memory_manager.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:14:37 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/15 15:56:06 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	malloc_redir_tab(t_input *input)
{
	input->redir_tab = malloc((input->n_cmd + 1) * sizeof(char ***));
	if (!input->redir_tab)
		return (1);
	input->redir_tab[input->n_cmd] = NULL;
	return (0);
}

int	malloc_redir_subdiv(t_input *input)
{
	int	i_cmd;

	i_cmd = -1;
	while (input->cmd_tab[++i_cmd])
	{
		input->redir_tab[i_cmd] = malloc(5 * sizeof(char **));
		if (!input->redir_tab[i_cmd])
			return (1);
		input->redir_tab[i_cmd][4] = NULL;
	}
	return (0);
}

int	malloc_redir_solo(t_input *input)
{
	int	i_cmd;
	int	i_red_type;

	i_cmd = -1;
	while (input->redir_tab[++i_cmd])
	{
		i_red_type = -1;
		while (++i_red_type < 4)
		{
			if (i_red_type == 0)
				malloc_input_name(input, &i_cmd);
			if (i_red_type == 1)
				malloc_output_name(input, &i_cmd);
			if (i_red_type == 2)
				malloc_heredoc_name(input, &i_cmd);
			if (i_red_type == 3)
				malloc_app_output_name(input, &i_cmd);
		}
	}
	return (0);
}
