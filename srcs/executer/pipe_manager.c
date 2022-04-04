/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:32:58 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/04 17:12:13 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	open_all_pipes(t_cmd_lst *cmd)
{
	t_cmd_lst	*start;
	int			i;

	i = -1;
	start = cmd;
	while (cmd)
	{
		if (!open_single_pipe(cmd->cmd_pipe))
			return (-1);
		if (cmd->next == NULL)
			break ;
		cmd = cmd->next;
	}
	cmd = start;
	return (0);
}

int	open_single_pipe(int *fd_tab)
{
	if (pipe(fd_tab) == -1)
		return (stderror_return(0, "minishelled", "pipe", "open pipe failed"));
	return (1);
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
