/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredocs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:38:12 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/22 12:58:29 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	get_heredoc_str(t_input *input, t_cmd_lst *cmd);
static int	get_str_from_child(t_input *input, t_cmd_lst *cmd, char *str);

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

static int	get_heredoc_str(t_input *input, t_cmd_lst *cmd)
{
	int		status;
	char	*str;

	status = 0;
	str = NULL;
	if (open_single_pipe(cmd->heredoc_pipe) == FAILED)
		return (FAILED);
	cmd->heredoc_process = fork();
	check_fork_error(cmd->heredoc_process);
	if (cmd->heredoc_process == CHILD)
		status = get_str_from_child(input, cmd, str);
	waitpid(cmd->heredoc_process, &status, 0);
	return (status);
}

static int	get_str_from_child(t_input *input, t_cmd_lst *cmd, char *str)
{
	int	i;

	i = -1;
	set_signals(HEREDOC);
	while (++i < cmd->n_heredoc)
		str = build_heredoc_str(input, cmd->del[i]);
	if (!str)
		exit(FAILED);
	// mettre fonction d'Alex ici
	ft_putstr_fd(str, cmd->heredoc_pipe[1]);
	exit (0);
}
