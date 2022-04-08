/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:14:03 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/08 18:51:09 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	open_files(t_input *input, t_cmd_lst *cmd)
{
	t_cmd_lst	*start;

	start = cmd;
	while (cmd)
	{
		if (cmd->n_infile > 0)
			if (open_infiles(input, cmd) == 1)
				return (1);
		if (cmd->n_outfile > 0)
			if (open_outfiles(input, cmd) == 1)
				return (1);
		if (cmd->n_app_outfile > 0)
			if(open_app_outfiles(input, cmd) == 1)
				return (1);
		if (cmd->next == NULL)
			break ;
		cmd = cmd->next;
	}
	cmd = start;
	return (0);
}

int	open_infiles(t_input *input, t_cmd_lst *cmd)
{
	int	i;

	cmd->fd_infile = ft_malloc(input, sizeof(int), cmd->n_infile);
	input->garbage->type = CMD_LST;
	i = -1;
	while (++i < cmd->n_infile)
	{
		cmd->fd_infile[i] = open(cmd->infile[i], O_RDONLY);
		if (cmd->fd_infile[i] < 0)
			return (stderror_return(1, cmd->name, cmd->infile[i], "No such file or directory"));
	}
	return (0);
}

int	open_outfiles(t_input *input, t_cmd_lst *cmd)
{
	int	i;

	cmd->fd_outfile = ft_malloc(input, sizeof(int), cmd->n_outfile);
	input->garbage->type = CMD_LST;
	i = -1;
	while (++i < cmd->n_outfile)
	{
		cmd->fd_outfile[i] = open(cmd->outfile[i], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (cmd->fd_outfile[i] < 0)
			return (stderror_return(1, cmd->name, cmd->infile[i], "No such file or directory"));
	}
	return (0);
}

int	open_app_outfiles(t_input *input, t_cmd_lst *cmd)
{
	int	i;

	cmd->fd_app_outfile = ft_malloc(input, sizeof(int), cmd->n_app_outfile);
	input->garbage->type = CMD_LST;
	i = -1;
	while (++i < cmd->n_app_outfile - 1)
	{
		cmd->fd_app_outfile[i] = open(cmd->app_outfile[i],
				O_CREAT | O_RDWR | O_APPEND, 0644);
		if (cmd->fd_app_outfile[i] < 0)
			return (stderror_return(1, cmd->name, cmd->infile[i], "No such file or directory"));
	}
	return (0);
}
