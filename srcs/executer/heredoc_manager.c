/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:38:12 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/08 19:09:42 by llethuil         ###   ########lyon.fr   */
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
			cmd->heredoc_str = get_heredoc_str(input, cmd);
		if (!cmd->heredoc_str || open_single_pipe(cmd->heredoc_pipe) == FAILED)
			return (FAILED);
			ft_putstr_fd(cmd->heredoc_str, cmd->heredoc_pipe[1]);
		cmd = cmd->next;
	}
	cmd = start;
	return (0);
}

char	*get_heredoc_str(t_input *input, t_cmd_lst *cmd)
{
	int				i;
	unsigned int	del_len;
	char			*heredoc_str;

	i = -1;
	heredoc_str = NULL;
	while (++i < cmd->n_heredoc)
	{
		del_len = ft_strlen(cmd->del[i]);
		heredoc_str = build_heredoc_str(input, cmd->del[i], del_len);
	}
	return (heredoc_str);
}

char *build_heredoc_str(t_input *input, char *del, unsigned long del_len)
{
	char	*heredoc_str;
	char	*line;
	int		i;
	// Apres le fork, faire signal(SIGINT, SIG_DFL)
	line = NULL;
	heredoc_str = NULL;
	i = 0;
	while (ft_strncmp(line, del, del_len) != 0 || ft_strlen(line) - 1 != del_len)
	{
		line = read_heredoc_line(input);
		if (ft_strncmp(line, del, del_len) != 0 || ft_strlen(line) - 1 != del_len)
		{
			if (i++ == 0)
				heredoc_str = ft_strdup(input, line);
			else
				heredoc_str = append_heredoc_line(input, line, heredoc_str);
			input->garbage->type = CMD_LST;
		}
	}
	return (heredoc_str);
}

char	*read_heredoc_line(t_input *input)
 {
	char	*new_line;
	char	*buffer;

	new_line = readline("> ");
	// printf("new_line = %s\n", new_line);
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

