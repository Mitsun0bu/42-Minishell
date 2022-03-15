/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:14:03 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/15 11:25:37 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	open_files(t_cmd_lst **cmd)
{
	t_cmd_lst	*start;

	start = *cmd;
	while (*cmd)
	{
		if ((*cmd)->n_input_redir > 0)
			open_infiles(*cmd);
		if ((*cmd)->n_output_redir > 0)
			open_outfiles(*cmd);
		if ((*cmd)->n_app_output_redir > 0)
			open_app_outfiles(*cmd);
		*cmd = (*cmd)->next;
	}
	*cmd = start;
	return (0);
}

int	open_infiles(t_cmd_lst *cmd)
{
	int	i;

	cmd->fd_input = safe_malloc(sizeof(int), cmd->n_input_redir);
	i = -1;
	while (++i < cmd->n_input_redir)
	{
		cmd->fd_input[i] = open(cmd->input_redir[i], O_RDONLY);
		if (cmd->fd_input[i] < 0)
		{
			perror(cmd->input_redir[i]);
			if (cmd->next == NULL)
				exit(0);
			else
				break ;
		}
	}
	return (0);
}

int	open_outfiles(t_cmd_lst *cmd)
{
	int	i;

	cmd->fd_output = safe_malloc(sizeof(int), cmd->n_output_redir);
	i = -1;
	while (++i < cmd->n_output_redir)
	{
		cmd->fd_output[i] = open(cmd->output_redir[i], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (cmd->fd_output[i] < 0)
		{
			perror(cmd->output_redir[i]);
			exit(0);
		}
	}
	return (0);
}

int	open_app_outfiles(t_cmd_lst *cmd)
{
	int	i;

	cmd->fd_app_output = safe_malloc(sizeof(int), cmd->n_app_output_redir);
	i = -1;
	while (++i < cmd->n_app_output_redir)
	{
		cmd->fd_app_output[i] = open(cmd->app_output_redir[i], O_CREAT | O_RDWR | O_APPEND, 0644);
		if (cmd->fd_app_output[i] < 0)
		{
			perror(cmd->app_output_redir[i]);
			exit(0);
		}
	}
	return (0);
}
