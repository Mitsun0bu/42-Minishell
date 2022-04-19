/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:38:12 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/19 18:36:21 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	handle_heredocs(t_input *input, t_cmd_lst *cmd)
{
	int			i;
	t_cmd_lst	*start;

	i = -1;
	start = cmd;
	while (cmd)
	{
		if (cmd->n_heredoc)
			if (get_heredoc_str(input, cmd) != 0)
				return (FAILED);
		cmd = cmd->next;
	}
	cmd = start;
	return (0);
}

int	get_heredoc_str(t_input *input, t_cmd_lst *cmd)
{
	int		status;
	char	*heredoc_str;

	status = 0;
	heredoc_str = NULL;
	if (open_single_pipe(cmd->heredoc_pipe) == FAILED)
		return (FAILED);
	cmd->heredoc_process = fork();
	check_fork_error(cmd->heredoc_process);
	if (cmd->heredoc_process == CHILD)
		status = get_heredoc_child(input, cmd, heredoc_str);
	waitpid(cmd->heredoc_process, &status, 0);
	return (status);
}

int	get_heredoc_child(t_input *input, t_cmd_lst *cmd, char *heredoc_str)
{
	int	i;

	i = -1;
	signal(SIGINT, signal_handler_heredoc);
	while (++i < cmd->n_heredoc)
		heredoc_str = build_heredoc_str(input, cmd->del[i]);
	if (!heredoc_str)
		exit(FAILED);
	ft_putstr_fd(heredoc_str, cmd->heredoc_pipe[1]);
	exit (0);
}
