/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_redir_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:07:06 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/07 11:40:30 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	handle_infile(t_input *input, t_cmd_lst *cmd)
{
	int	i;

	i = -1;
	if (cmd->n_infile && input->last_infile_type[cmd->i] == INPUT)
	{
		while (++i < cmd->n_infile)
		{
			if (cmd->fd_infile[i] > 0)
				dup2(cmd->fd_infile[i], STDIN_FILENO);
			else
				return (FAILED);
		}
	}
	else if (input->last_infile_type[cmd->i] == HEREDOC)
	{
		if (!cmd->heredoc_str)
		{
			close_single_pipe(cmd->heredoc_pipe);
			return (0);
		}
		dup2(cmd->heredoc_pipe[0], STDIN_FILENO);
		close_single_pipe(cmd->heredoc_pipe);
	}
	if (i == -1)
		return (0);
	return (1);
}

int	handle_outfile(t_input *input, t_cmd_lst *cmd)
{
	int	i;

	i = -1;
	if (cmd->n_app_outfile && input->last_outfile_type[cmd->i] == TRUNC_OUTPUT)
	{
		while (++i < cmd->n_app_outfile)
			dup2(cmd->fd_app_outfile[i], STDOUT_FILENO);
		i = -1;
		while (++i < cmd->n_outfile)
			dup2(cmd->fd_outfile[i], STDOUT_FILENO);
	}
	else if (cmd->n_outfile && input->last_outfile_type[cmd->i] == APP_OUTPUT)
	{
		while (++i < cmd->n_outfile)
			dup2(cmd->fd_outfile[i], STDOUT_FILENO);
		i = -1;
		while (++i < cmd->n_app_outfile)
			dup2(cmd->fd_app_outfile[i], STDOUT_FILENO);
	}
	if (i == -1)
		return (0);
	return (1);
}
