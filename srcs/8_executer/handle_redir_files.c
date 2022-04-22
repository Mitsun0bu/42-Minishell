/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir_files.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:11:39 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/22 10:13:39 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	dup_loop(int n_file, int *fd_file, int where);

int	handle_infile(t_input *input, t_cmd_lst *cmd)
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

int	handle_outfile(t_input *input, t_cmd_lst *cmd)
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
