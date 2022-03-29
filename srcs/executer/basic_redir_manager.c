/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_redir_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:07:06 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/29 10:54:46 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	handle_infile(t_input *input, t_cmd_lst *cmd)
{
	int	i;

	i = -1;
	if (input->last_input_type_tab[cmd->index] == INPUT)
	{
		if (cmd->n_infile)
			while (++i < cmd->n_infile)
				dup2(cmd->fd_input[i], STDIN_FILENO);
	}
	else if (input->last_input_type_tab[cmd->index] == HEREDOC)
	{
		dup2(cmd->heredoc_pipe[0], STDIN_FILENO);
		close_single_pipe(cmd->heredoc_pipe);
	}
	return (i);
}

int	handle_outfile(t_input *input, t_cmd_lst *cmd)
{
	int	i;

	i = -1;
	if (input->last_output_type_tab[cmd->index] == TRUNC_OUTPUT)
	{
		if (cmd->n_app_outfile)
			while (++i < cmd->n_app_outfile)
				dup2(cmd->fd_app_output[i], STDOUT_FILENO);
		i = -1;
		while (++i < cmd->n_outfile)
			dup2(cmd->fd_output[i], STDOUT_FILENO);
	}
	else if (input->last_output_type_tab[cmd->index] == APP_OUTPUT)
	{
		if (cmd->n_outfile)
			while (++i < cmd->n_outfile)
				dup2(cmd->fd_output[i], STDOUT_FILENO);
		i = -1;
		while (++i < cmd->n_app_outfile)
			dup2(cmd->fd_app_output[i], STDOUT_FILENO);
	}
	return (i);
}
