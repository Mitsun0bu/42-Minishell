/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:02:15 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/12 18:10:07 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_line(t_input *input, char *line, char *buff, int fd);
static char	*ft_strjoin_gnl(t_input *input, char *line, char *buff);
static int	ft_find_nl_index(char *str);
static int	ft_determine_buff_size(char *buff);

char	*ft_get_next_line(t_input *input, int fd)
{
	static char	buff[BUFFER_SIZE + 1] = {};
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_malloc(input, sizeof(char), 1);
	input->gb->type = GARBAGE;
	line[0] = 0;
	line = ft_get_line(input, line, buff, fd);
	if (line && ft_strlen(line))
	{
		line = ft_strtrim(input, line, "\n");
		input->gb->type = GARBAGE;
		return (line);
	}
	return (NULL);
}

static char	*ft_get_line(t_input *input, char *line, char *buff, int fd)
{
	int		read_ret;
	char	*buff_rest;

	read_ret = 1;
	while (read_ret > 0)
	{
		line = ft_strjoin_gnl(input, line, buff);
		input->gb->type = GARBAGE;
		if (ft_find_nl_index(buff) != -1)
		{
			buff_rest = &buff[ft_find_nl_index(buff) + 1];
			while (*buff_rest)
				*buff++ = *buff_rest++;
			*buff = '\0';
			return (line);
		}
		read_ret = read(fd, buff, BUFFER_SIZE);
		if (read_ret == -1)
			ft_free((void *)&line);
		if (read_ret == -1)
			return (NULL);
		buff[read_ret] = '\0';
	}
	return (line);
}

static char	*ft_strjoin_gnl(t_input *input, char *line, char *buff)
{
	char	*joined;
	int		buff_size;
	int		i_l;
	int		i_b;

	buff_size = ft_determine_buff_size(buff);
	joined = ft_malloc(input, sizeof(char), ft_strlen(line) + buff_size + 2);
	i_l = -1;
	while (line[++i_l])
		joined[i_l] = line[i_l];
	i_b = -1;
	while (buff[++i_b])
	{
		joined[i_l] = buff[i_b];
		if (buff[i_b] == '\n')
		{
			i_l ++;
			break ;
		}
		i_l ++;
	}
	joined[i_l] = '\0';
	return (joined);
}

static int	ft_find_nl_index(char *str)
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

static int	ft_determine_buff_size(char *buff)
{
	int	buff_size;

	buff_size = 0;
	if (ft_find_nl_index(buff) == -1)
		buff_size = ft_strlen(buff);
	else
		buff_size = ft_find_nl_index(buff);
	return (buff_size);
}
