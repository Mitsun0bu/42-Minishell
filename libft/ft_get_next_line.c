/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:02:15 by llethuil          #+#    #+#             */
/*   Updated: 2021/12/15 15:05:06 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_line(char *line, char *buff, int fd);
char	*ft_strjoin_gnl(char *line, char *buff);
int		ft_position_nl(char *str);

char	*ft_get_next_line(int fd)
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
		line = ft_strjoin_gnl(line, buff);
		if (!line)
			return (NULL);
		if (ft_position_nl(buff) != -1)
		{
			buff_rest = &buff[ft_position_nl(buff) + 1];
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

char	*ft_strjoin_gnl(char *line, char *buff)
{
	char	*joined;
	int		buff_size;
	int		i_l;
	int		i_b;

	if (ft_position_nl(buff) != -1)
		buff_size = ft_position_nl(buff) + 1;
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

int	ft_position_nl(char *str)
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
