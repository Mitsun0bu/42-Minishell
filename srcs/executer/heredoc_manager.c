/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:38:12 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/16 17:39:04 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	handle_heredocs_pipes(t_cmd_lst **cmd)
{
	t_cmd_lst	*start;

	start = *cmd;
	while (*cmd)
	{
		(*cmd)->heredoc_str = read_cmd_heredocs(*cmd);
		open_single_pipe((*cmd)->heredoc_pipe);
		ft_putstr_fd((*cmd)->heredoc_str, (*cmd)->heredoc_pipe[1]);
		*cmd = (*cmd)->next;
	}
	*cmd = start;
	return (0);
}

char	*read_cmd_heredocs(t_cmd_lst *cmd)
{
	int		i;
	char	*line;
	char	*heredoc_str;

	heredoc_str = ft_calloc(0, 0);
	i = -1;
	while (++i < cmd->n_heredoc)
	{
		if (i == 0)
		{
			line = read_heredoc_line();
			if (ft_strncmp(line, cmd->del[i], ft_strlen(cmd->del[i])) != 0
				|| ft_strlen(line) - 1 != ft_strlen(cmd->del[i]))
				heredoc_str = ft_strdup(line);
		}
		while (ft_strncmp(line, cmd->del[i], ft_strlen(cmd->del[i])) != 0
			|| ft_strlen(line) - 1 != ft_strlen(cmd->del[i]))
		{
			line = read_heredoc_line();
			if (ft_strncmp(line, cmd->del[i], ft_strlen(cmd->del[i])) != 0
				|| ft_strlen(line) - 1 != ft_strlen(cmd->del[i]))
				heredoc_str = append_heredoc_line(line, heredoc_str);
		}
	}
	return (heredoc_str);
}

char	*read_heredoc_line(void)
{
	char	*line;
	char	*buffer;

	line = readline("> ");
	buffer = line;
	line = ft_strjoin(buffer, "\n");
	ft_free((void *)&buffer);
	return (line);
}

char	*append_heredoc_line(char *line, char *heredoc_str)
{
	char	*new_heredoc_str;
	char	*buffer;

	buffer = heredoc_str;
	ft_free((void *)&heredoc_str);
	new_heredoc_str = ft_strjoin(buffer, line);
	return (new_heredoc_str);
}
