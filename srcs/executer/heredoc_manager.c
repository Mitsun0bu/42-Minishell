/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:38:12 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/21 14:01:43 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	handle_heredocs_pipes(t_cmd_lst **cmd)
{
	t_cmd_lst	*start;

	start = *cmd;
	while (*cmd)
	{
		if ((*cmd)->n_heredoc)
		{
			(*cmd)->heredoc_str = read_cmd_heredocs(*cmd);
			open_single_pipe((*cmd)->heredoc_pipe);
			ft_putstr_fd((*cmd)->heredoc_str, (*cmd)->heredoc_pipe[1]);
		}
		*cmd = (*cmd)->next;
	}
	*cmd = start;
	return (0);
}

char	*read_cmd_heredocs(t_cmd_lst *cmd)
{
	int		i;
	int		j;
	char	*line;
	char	*heredoc_str;

	line = NULL;
	heredoc_str = NULL;
	i = -1;
	while (++i < cmd->n_heredoc - 1)
		while (ft_strncmp(line, cmd->del[i], ft_strlen(cmd->del[i])) != 0
			|| ft_strlen(line) - 1 != ft_strlen(cmd->del[i]))
			line = read_heredoc_line(line);
	j = 0;
	while (ft_strncmp(line, cmd->del[i], ft_strlen(cmd->del[i])) != 0
		|| ft_strlen(line) - 1 != ft_strlen(cmd->del[i]))
	{
		line = read_heredoc_line(line);
		if (j++ == 0)
			heredoc_str = ft_strdup(line);
		else if (ft_strncmp(line, cmd->del[i], ft_strlen(cmd->del[i])) != 0
			|| ft_strlen(line) - 1 != ft_strlen(cmd->del[i]))
			heredoc_str = append_heredoc_line(line, heredoc_str);
	}
	ft_free((void *)&line);
	return (heredoc_str);
}

char	*read_heredoc_line(char *line)
{
	char	*new_line;
	char	*buffer;

	ft_free((void *)&line);
	new_line = readline("> ");
	buffer = new_line;
	new_line = ft_strjoin(buffer, "\n");
	ft_free((void *)&buffer);
	return (new_line);
}

char	*append_heredoc_line(char *line, char *heredoc_str)
{
	char	*new_heredoc_str;
	char	*buffer;

	buffer = heredoc_str;
	new_heredoc_str = ft_strjoin(buffer, line);
	ft_free((void *)&heredoc_str);
	return (new_heredoc_str);
}
