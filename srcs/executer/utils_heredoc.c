/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:14:08 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/11 15:14:37 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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