/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:38:19 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/23 16:53:14 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "main.h"

int	get_cmd_line(t_input *input)
{
	char	*buff;

	buff = readline("minishelled > ");
	while(!ft_strncmp(buff, "", ft_strlen(buff)))
		buff = readline("minishelled > ");
	if (ft_strlen(buff))
	{
		add_history(buff);
		input->fd_history = open("minishelled_history.txt", O_CREAT | O_RDWR | O_APPEND, 0644);
		if (input->fd_history < 0)
		{
			printf("Couldn't open history file");
			exit(0);
		}
		write(input->fd_history, buff, ft_strlen(buff));
		write(input->fd_history, "\n", 1);
		input->cmd_line = ft_strdup(buff);
		ft_free (buff);
		return (0);
	}
	close (input->fd_history);
	return (1);
}