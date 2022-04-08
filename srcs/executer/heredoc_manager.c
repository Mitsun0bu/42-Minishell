/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:38:12 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/08 17:37:34 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	get_heredoc_str(t_input *input, t_cmd_lst *cmd)
{
	if (cmd->n_heredoc)
	{
		cmd->heredoc_str = read_cmd_heredocs(input, cmd);
		if (!cmd->heredoc_str || open_single_pipe(cmd->heredoc_pipe) == FAILED)
			return (FAILED);
		ft_putstr_fd(cmd->heredoc_str, cmd->heredoc_pipe[1]);
	}
	return (0);
}

char	*read_cmd_heredocs(t_input *input, t_cmd_lst *cmd)
{
	int		i;
	int		j;
	unsigned long	del_len;
	char	*line;
	char	*heredoc_str;

	line = NULL;
	heredoc_str = NULL;
	i = -1;
	while (++i < cmd->n_heredoc)
	{
		del_len = ft_strlen(cmd->del[i]);
		j = 0;
		while (ft_strncmp(line, cmd->del[i], del_len) != 0 || ft_strlen(line) - 1 != del_len)
		{
			line = read_heredoc_line(input);
			if (ft_strncmp(line, cmd->del[i], del_len) != 0 || ft_strlen(line) - 1 != del_len)
			{
				if (j++ == 0)
					heredoc_str = ft_strdup(input, line);
				else
					heredoc_str = append_heredoc_line(input, line, heredoc_str);
				input->garbage->type = CMD_LST;
			}
		}
	}
	return (heredoc_str);
}

char	*read_heredoc_line(t_input *input)
 {
	char	*new_line;
	char	*buffer;

	new_line = readline("> ");
	printf("new_line = %s\n", new_line);
	if (!new_line)
		return (NULL);
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
