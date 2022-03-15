/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:32:58 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/15 11:41:57 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	open_all_pipes(t_cmd_lst **cmd)
{
	t_cmd_lst	*start;
	int			i;

	i = -1;
	start = *cmd;
	while (*cmd)
	{
		open_single_pipe((*cmd)->cmd_pipe);
		if ((*cmd)->next == NULL)
			break ;
		*cmd = (*cmd)->next;
	}
	*cmd = start;
}

void	open_single_pipe(int *fd_tab)
{
	if (pipe(fd_tab) == -1)
	{
		perror("");
		exit (1);
	}
}

void	close_all_pipes(t_cmd_lst *cmd)
{
	int	i;

	i = -1;
	while (cmd->previous)
		cmd = cmd->previous;
	while (cmd)
	{
		close_single_pipe(cmd->cmd_pipe);
		if (cmd->n_heredoc)
			close_single_pipe(cmd->heredoc_pipe);
		cmd = cmd->next;
	}
}

void	close_single_pipe(int *fd_tab)
{
	close(fd_tab[0]);
	close(fd_tab[1]);
}
