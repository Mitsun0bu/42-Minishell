/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:38:19 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/29 15:06:43 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	get_cmd_line(t_input *input)
{
	char	*path;
	char	*buff;

	path = get_history_path(input);
	buff = readline("minishelled > ");
	while (!ft_strncmp(buff, "", ft_strlen(buff)))
		buff = readline("minishelled > ");
	if (ft_strlen(buff))
	{
		add_history(buff);
		input->fd_history = open(path, O_CREAT | O_RDWR | O_APPEND, 0644);
		if (input->fd_history < 0)
			stderror_exit(input, -1, "error", ": couldn't open history file");
		write(input->fd_history, buff, ft_strlen(buff));
		write(input->fd_history, "\n", 1);
		input->cmd_line = ft_strdup(input, buff);
		input->garbage->type = CMD_LINE;
		ft_free((void *)&buff);
	}
	close (input->fd_history);
}
