/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:38:19 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/14 12:05:27 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cmd_line_handler.h"

int	get_cmd_line(t_input *input, int fd)
{
	char	*buff;

	(void)fd;
	buff = readline("minishelled > ");
	while(!ft_strncmp(buff, "", ft_strlen(buff)))
		buff = readline("minishelled > ");
	if (ft_strlen(buff))
	{
		add_history(buff);
		write(fd, buff, ft_strlen(buff));
		write(fd, "\n", 1);
		input->cmd_line = ft_strdup(buff);
		free (buff);
		return (0);
	}
	return (1);
}

int	open_history_file(void)
{
	int	fd;

	fd = open("minishelled_history.txt", O_CREAT | O_RDWR, 0644);
	if (fd < 0)
	{
		printf("Couldn't open history file");
		exit(0);
	}
	return (fd);
}

int	get_history(int	fd)
{
	char	*cmd_line_history;
	cmd_line_history = "init";
	while (cmd_line_history)
	{
		cmd_line_history = get_next_line(fd);
		add_history(cmd_line_history);
		free(cmd_line_history);
	}
	return (0);
}