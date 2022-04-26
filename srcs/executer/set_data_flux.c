/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_flux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:07:06 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/26 15:35:38 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	handle_infile(t_input *input, t_cmd_lst *cmd);
static int	handle_outfile(t_input *input, t_cmd_lst *cmd);
static int	dup_loop(int n_file, int *fd_file, int where);

int	set_stdin(t_input *input, t_cmd_lst *cmd)
{
	int	job_done;

	job_done = NO;
	if (cmd->i != 0 && cmd->n_infile == 0 && cmd->n_heredoc == 0)
		dup2(cmd->previous->cmd_pipe[0], STDIN_FILENO);
	else if (cmd->n_infile || cmd->n_heredoc)
	{
		job_done = handle_infile(input, cmd);
		if (job_done == YES)
			return (SUCCESS);
		else if (cmd->i != 0 && job_done == NO)
		{
			if (cmd->valid_path || cmd_is_built_in(cmd->name) == YES)
				dup2(cmd->previous->cmd_pipe[0], STDIN_FILENO);
		}
		else
		{
			g_status = 1;
			return (FAILED);
		}
	}
	return (SUCCESS);
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
		if (job_done == YES)
			return ;
		else if (cmd->next != NULL || job_done == NO)
			if (cmd->valid_path || cmd_is_built_in(cmd->name) == YES)
				dup2(cmd->cmd_pipe[1], STDOUT_FILENO);
	}
}

static int	handle_infile(t_input *input, t_cmd_lst *cmd)
{
	if (input->last_infile_type[cmd->i] == INFILE)
	{
		if (!dup_loop(cmd->n_infile, cmd->fd_infile, STDIN_FILENO))
			return (NO);
		else
			return (YES);
	}
	else if (input->last_infile_type[cmd->i] == HEREDOC)
	{
		dup2(cmd->heredoc_pipe[0], STDIN_FILENO);
		close_single_pipe(cmd->heredoc_pipe);
		return (YES);
	}
	else
		return (NO);
}

static int	handle_outfile(t_input *input, t_cmd_lst *cmd)
{
	if (input->last_outfile_type[cmd->i] == OUTFILE)
	{
		if (!dup_loop(cmd->n_app_outfile, cmd->fd_app_outfile, STDOUT_FILENO))
			return (NO);
		if (!dup_loop(cmd->n_outfile, cmd->fd_outfile, STDOUT_FILENO))
			return (NO);
		else
			return (YES);
	}
	else if (input->last_outfile_type[cmd->i] == APP_OUTFILE)
	{
		if (!dup_loop(cmd->n_outfile, cmd->fd_outfile, STDOUT_FILENO))
			return (NO);
		if (!dup_loop(cmd->n_app_outfile, cmd->fd_app_outfile, STDOUT_FILENO))
			return (NO);
		else
			return (YES);
	}
	else
		return (NO);
}

static int	dup_loop(int n_file, int *fd_file, int where)
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
				dup2(fd_file[i], STDOUT_FILENO);
		}
		else
			return (NO);
	}
	return (YES);
}