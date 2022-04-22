/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:14:08 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/22 09:12:00 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char	*read_heredoc_line(t_input *input);
static char	*append_heredoc_line(t_input *input, char *line, char *str);

char	*build_heredoc_str(t_input *input, char *del)
{
	char			*line;
	char			*str;
	unsigned long	len;

	line = NULL;
	str = ft_strdup(input, "");
	input->gb->type = GARBAGE;
	len = ft_strlen(del);
	while (ft_strncmp(line, del, len) != 0 || ft_strlen(line) - 1 != len)
	{
		line = read_heredoc_line(input);
		if (!line)
			return (NULL);
		if (ft_strncmp(line, del, len) != 0 || ft_strlen(line) - 1 != len)
		{
			str = append_heredoc_line(input, line, str);
			input->gb->type = GARBAGE;
		}
	}
	return (str);
}

static char	*read_heredoc_line(t_input *input)
{
	char	*line;
	char	*buffer;

	line = readline("> ");
	if (!line)
		return (NULL);
	buffer = ft_strdup(input, line);
	input->gb->type = GARBAGE;
	ft_free((void *)&line);
	line = ft_strjoin(input, buffer, "\n");
	input->gb->type = GARBAGE;
	return (line);
}

static char	*append_heredoc_line(t_input *input, char *line, char *str)
{
	char	*append_line;
	char	*buffer;

	buffer = str;
	append_line = ft_strjoin(input, buffer, line);
	return (append_line);
}
