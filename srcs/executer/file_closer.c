/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_closer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:14:03 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/20 09:46:03 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	close_all_files(t_cmd_lst *cmd)
{
	t_cmd_lst	*start;

	start = cmd;
	while (cmd)
	{
		if (cmd->n_infile > 0)
			if (close_infiles(cmd) == FAILED)
				return (FAILED);
		if (cmd->n_outfile > 0)
			if (close_outfiles(cmd) == FAILED)
				return (FAILED);
		if (cmd->n_app_outfile > 0)
			if (close_app_outfiles(cmd) == FAILED)
				return (FAILED);
		if (cmd->next == NULL)
			break ;
		cmd = cmd->next;
	}
	cmd = start;
	return (SUCCESS);
}

int	close_infiles(t_cmd_lst *cmd)
{
	int	i;

	i = -1;
	while (++i < cmd->n_infile)
	{
		if (close(cmd->fd_infile[i]) == FAILED)
		{
			print_err(1, NULL, cmd->infile[i], "close() failed");
			return (FAILED);
		}
	}
	return (SUCCESS);
}

int	close_outfiles(t_cmd_lst *cmd)
{
	int	i;

	i = -1;
	while (++i < cmd->n_outfile)
	{
		if (close(cmd->fd_outfile[i]) == FAILED)
		{
			print_err(1, NULL, cmd->outfile[i], "close() failed");
			return (FAILED);
		}
	}
	return (SUCCESS);
}

int	close_app_outfiles(t_cmd_lst *cmd)
{
	int	i;

	i = -1;
	while (++i < cmd->n_app_outfile)
	{
		if (close(cmd->fd_app_outfile[i]) == FAILED)
		{
			print_err(1, NULL, cmd->app_outfile[i], "close() failed");
			return (FAILED);
		}
	}
	return (SUCCESS);
}
