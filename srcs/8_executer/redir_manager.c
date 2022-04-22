/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:07:06 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/22 10:13:45 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	set_stdin(t_input *input, t_cmd_lst *cmd)
{
	int	job_done;

	job_done = NO;
	if (cmd->i != 0 && cmd->n_infile == 0 && cmd->n_heredoc == 0)
		dup2(cmd->previous->cmd_pipe[0], STDIN_FILENO);
	else if (cmd->n_infile || cmd->n_heredoc)
	{
		job_done = handle_infile(input, cmd);
		if (cmd->i != 0 || job_done == NO)
			if (cmd->valid_path || cmd_is_built_in(cmd->name) == YES)
				dup2(cmd->previous->cmd_pipe[0], STDIN_FILENO);
	}
}

void	set_stdout(t_input *input, t_cmd_lst *cmd)
{
	int	job_done;

	job_done = NO;
	if (cmd->next != NULL && cmd->n_outfile == 0 && cmd->n_app_outfile == 0)
		dup2(cmd->cmd_pipe[1], STDOUT_FILENO);
	else if (cmd->n_outfile || cmd->n_app_outfile)
	{
		job_done = handle_outfile(input, cmd);
		if (cmd->next != NULL || job_done == NO)
			if (cmd->valid_path || cmd_is_built_in(cmd->name) == YES)
				dup2(cmd->cmd_pipe[1], STDOUT_FILENO);
	}
}
