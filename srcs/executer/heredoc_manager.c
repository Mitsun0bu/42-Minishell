/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:38:12 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/11 14:35:09 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	handle_heredocs(t_input *input, t_cmd_lst *cmd)
{
	int	i;
	t_cmd_lst	*start;

	i = -1;
	start = cmd;
	while (cmd)
	{
		if(cmd->n_heredoc)
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
	if(open_single_pipe(cmd->heredoc_pipe) == FAILED)
		return (FAILED);
	heredoc_str = NULL;
	cmd->heredoc_process = fork();
	check_fork_error(cmd->heredoc_process);
	if (cmd->heredoc_process == 0)
		status = get_heredoc_from_child(input, cmd, heredoc_str);
	signal(SIGINT, SIG_IGN);
	waitpid(cmd->heredoc_process, &status, 0);
	signal(SIGINT, signal_handler_parent);
	return (status);
}

int	get_heredoc_from_child(t_input *input, t_cmd_lst *cmd, char *heredoc_str)
{
	int	i;

	i = -1;
	signal(SIGINT, SIG_DFL);
	while (++i < cmd->n_heredoc)
		heredoc_str = build_heredoc_str(input, cmd->del[i]);
	if (!heredoc_str)
		exit(FAILED);
	ft_putstr_fd(heredoc_str, cmd->heredoc_pipe[1]);
	exit (0);
}

char	*build_heredoc_str(t_input *input, char *del)
{
	int				i;
	char			*line;
	char			*heredoc_str;
	unsigned long	len;

	i = 0;
	line = NULL;
	heredoc_str = NULL;
	len = ft_strlen(del);
	while (ft_strncmp(line, del, len) != 0 || ft_strlen(line) - 1 != len)
	{
		line = read_heredoc_line(input);
		if (!line)
			return (NULL);
		if (ft_strncmp(line, del, len) != 0 || ft_strlen(line) - 1 != len)
		{
			if (i++ == 0)
				heredoc_str = ft_strdup(input, line);
			else
				heredoc_str = append_heredoc_line(input, line, heredoc_str);
			input->garbage->type = GARBAGE;
		}
	}
	return (heredoc_str);
}

char	*read_heredoc_line(t_input *input)
 {
	char	*new_line;
	char	*buffer;

	new_line = readline("> ");
	if (!new_line)
		return(NULL);
	buffer = ft_strdup(input, new_line);
	input->garbage->type = GARBAGE;
	ft_free((void *)&new_line);
	new_line = ft_strjoin(input, buffer, "\n");
	input->garbage->type = GARBAGE;
	return (new_line);
}

char	*append_heredoc_line(t_input *input, char *line, char *heredoc_str)
{
	char	*new_heredoc_str;
	char	*buffer;

	buffer = heredoc_str;
	new_heredoc_str = ft_strjoin(input, buffer, line);
	return (new_heredoc_str);
}
