/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:38:19 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/06 16:51:15 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	get_cmd_line(t_input *input)
{
	char	*path;
	char	*buff;

	path = get_history_path(input);
	buff = NULL;
	while (1)
	{
		printf("before buff\n");
		buff = readline("minishelled > ");
		printf("buff = %s\n", buff);
		if (!buff)
			stderror_exit(input, 0, NULL, "exit");
		if (ft_strlen(buff))
			break;
	}
	add_history(buff);
	if (path)
	{
		input->fd_history = open(path, O_CREAT | O_RDWR | O_APPEND, 0644);
		if (input->fd_history < 0)
			stderror_exit(input, -1, "error", ": couldn't open history file");
		ft_putstr_fd(ft_strjoin(input, buff, "\n"), input->fd_history);
		close (input->fd_history);
	}
	input->cmd_line = ft_strdup(input, buff);
	input->garbage->type = CMD_LINE;
	ft_free((void *)&buff);
}
