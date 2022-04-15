/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:07:06 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/15 17:25:06 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	set_stdin(t_input *input, t_cmd_lst *cmd)
{
	int	handle_infile_result;

	handle_infile_result = 0;
	if (cmd->n_infile == 0 && cmd->n_heredoc == 0)
	{
		if (cmd->i == 0)
			return (FAILED);
		else if (cmd->i != 0)
			dup2(cmd->previous->cmd_pipe[0], STDIN_FILENO);
	}
	else if (cmd->n_infile || cmd->n_heredoc)
	{
		handle_infile_result = handle_infile(input, cmd);
		if (handle_infile_result == FAILED)
			return (FAILED);
		else if (handle_infile_result == SUCCESS)
		{
			if (cmd->valid_path || is_built_in(cmd->name) == YES)
				dup2(cmd->previous->cmd_pipe[0], STDIN_FILENO);
			else
				return (FAILED);
		}
	}
	return (SUCCESS);
}

int	set_stdout(t_input *input, t_cmd_lst *cmd)
{
	int	handle_outfile_result;

	handle_outfile_result = 0;
	if (cmd->n_outfile == 0 && cmd->n_app_outfile == 0)
	{
		if (cmd->next == NULL)
			return (FAILED);
		else
			dup2(cmd->cmd_pipe[1], STDOUT_FILENO);
	}
	else if (cmd->n_outfile || cmd->n_app_outfile)
	{
		handle_outfile_result = handle_infile(input, cmd);
		if (handle_outfile_result == FAILED)
			return (FAILED);
		else if (handle_outfile_result == SUCCESS)
		{
			if (cmd->valid_path || is_built_in(cmd->name) == YES)
				dup2(cmd->cmd_pipe[1], STDOUT_FILENO);
			else
				return (FAILED);
		}
	}
	return (SUCCESS);
}

int	handle_infile(t_input *input, t_cmd_lst *cmd)
{
	if (input->last_infile_type[cmd->i] == INFILE)
	{
		if (dup_loop(cmd->n_infile, cmd->fd_infile, STDIN_FILENO) == FAILED)
			return (FAILED);
		else
			return (SUCCESS);
	}
	else if (input->last_infile_type[cmd->i] == HEREDOC)
	{
		dup2(cmd->heredoc_pipe[0], STDIN_FILENO);
		close_single_pipe(cmd->heredoc_pipe);
		return (SUCCESS);
	}
	else
		return (FAILED);
}

int	handle_outfile(t_input *input, t_cmd_lst *cmd)
{
	if (input->last_outfile_type[cmd->i] == OUTFILE)
	{
		if (dup_loop(cmd->n_app_outfile, cmd->fd_app_outfile, STDOUT_FILENO)
			== FAILED)
			return (FAILED);
		if (dup_loop(cmd->n_outfile, cmd->fd_outfile, STDOUT_FILENO)
			== FAILED)
			return (FAILED);
		else
			return (SUCCESS);
	}
	else if (input->last_outfile_type[cmd->i] == APP_OUTFILE)
	{
		if (dup_loop(cmd->n_outfile, cmd->fd_outfile, STDOUT_FILENO)
			== FAILED)
			return (FAILED);
		if (dup_loop(cmd->n_app_outfile, cmd->fd_app_outfile, STDOUT_FILENO)
			== FAILED)
			return (FAILED);
		else
			return (SUCCESS);
	}
	else
		return (FAILED);
}

int	dup_loop(int n_file, int *fd_file, int where)
{
	int	i;

	i = -1;
	while (++i < n_file)
	{
		if (fd_file[i] > 0)
		{
			if (where == STDIN_FILENO)
				dup2(fd_file[i], STDIN_FILENO);
			else if (where == STDOUT_FILENO)
				dup2(fd_file[i], STDIN_FILENO);
		}
		else
			return (FAILED);
	}
	return (SUCCESS);
}
