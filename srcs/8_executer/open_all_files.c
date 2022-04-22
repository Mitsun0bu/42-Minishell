/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_all_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:44:30 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/22 09:43:21 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	open_infiles(t_input *input, t_cmd_lst *cmd);
static int	open_outfiles(t_input *input, t_cmd_lst *cmd);
static int	open_app_outfiles(t_input *input, t_cmd_lst *cmd);

int	open_all_files(t_input *input, t_cmd_lst *cmd)
{
	t_cmd_lst	*start;

	start = cmd;
	while (cmd)
	{
		if (cmd->n_infile > 0)
			if (open_infiles(input, cmd) == FAILED)
				return (FAILED);
		if (cmd->n_outfile > 0)
			if (open_outfiles(input, cmd) == FAILED)
				return (FAILED);
		if (cmd->n_app_outfile > 0)
			if (open_app_outfiles(input, cmd) == FAILED)
				return (FAILED);
		if (cmd->next == NULL)
			break ;
		cmd = cmd->next;
	}
	cmd = start;
	return (SUCCESS);
}

static int	open_infiles(t_input *input, t_cmd_lst *cmd)
{
	int	i;

	cmd->fd_infile = ft_malloc(input, sizeof(int), cmd->n_infile);
	input->gb->type = CMD_LST;
	i = -1;
	while (++i < cmd->n_infile)
	{
		cmd->fd_infile[i] = open(cmd->infile[i], O_RDONLY);
		if (cmd->fd_infile[i] == FAILED)
		{
			print_err(1, cmd->name,
				cmd->infile[i], "No such file or directory");
			return (FAILED);
		}
	}
	return (SUCCESS);
}

static int	open_outfiles(t_input *input, t_cmd_lst *cmd)
{
	int	i;

	cmd->fd_outfile = ft_malloc(input, sizeof(int), cmd->n_outfile);
	input->gb->type = CMD_LST;
	i = -1;
	while (++i < cmd->n_outfile)
	{
		cmd->fd_outfile[i] = open(cmd->outfile[i],
				O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (cmd->fd_outfile[i] == FAILED)
		{
			print_err(1, cmd->name,
				cmd->outfile[i], "No such file or directory");
			return (FAILED);
		}
	}
	return (SUCCESS);
}

static int	open_app_outfiles(t_input *input, t_cmd_lst *cmd)
{
	int	i;

	cmd->fd_app_outfile = ft_malloc(input, sizeof(int), cmd->n_app_outfile);
	input->gb->type = CMD_LST;
	i = -1;
	while (++i < cmd->n_app_outfile)
	{
		cmd->fd_app_outfile[i] = open(cmd->app_outfile[i],
				O_CREAT | O_RDWR | O_APPEND, 0644);
		if (cmd->fd_app_outfile[i] == FAILED)
		{
			print_err(1, cmd->name,
				cmd->app_outfile[i], "No such file or directory");
			return (FAILED);
		}
	}
	return (SUCCESS);
}
