/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:02:15 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/14 12:05:20 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cmd_line_handler.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1] = {};
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = 0;
	line = ft_get_line(line, buff, fd);
	if (line && ft_strlen(line))
		return (line);
	free (line);
	return (NULL);
}

char	*ft_get_line(char *line, char *buff, int fd)
{
	int		read_ret;
	char	*buff_rest;

	read_ret = 1;
	while (read_ret > 0)
	{
		line = strjoin_gnl(line, buff);
		if (!line)
			return (NULL);
		if (position_nl(buff) != -1)
		{
			buff_rest = &buff[position_nl(buff) + 1];
			while (*buff_rest)
				*buff++ = *buff_rest++;
			*buff = '\0';
			return (line);
		}
		read_ret = read(fd, buff, BUFFER_SIZE);
		if (read_ret == -1)
			free (line);
		if (read_ret == -1)
			return (NULL);
		buff[read_ret] = '\0';
	}
	return (line);
}

int	position_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*strjoin_gnl(char *line, char *buff)
{
	char	*joined;
	int		buff_size;
	int		i_l;
	int		i_b;

	if (position_nl(buff) != -1)
		buff_size = position_nl(buff) + 1;
	else
		buff_size = ft_strlen(buff);
	joined = malloc(sizeof(char) * (ft_strlen(line) + buff_size + 1));
	if (!joined)
		return (NULL);
	i_l = -1;
	while (line[++i_l])
		joined[i_l] = line[i_l];
	free(line);
	i_b = 0;
	while (buff[i_b])
	{
		joined[i_l++] = buff[i_b++];
		if (buff[i_b - 1] == '\n')
			break ;
	}
	joined[i_l] = '\0';
	return (joined);
}