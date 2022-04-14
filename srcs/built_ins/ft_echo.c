/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:55:57 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/14 10:40:02 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_echo(t_input *input, t_cmd_lst *cmd)
{
	char	*message;

	message = NULL;
	if (!cmd->args[1])
		printf("\n");
	else if (!cmd->args[2] && !ft_strncmp(cmd->args[1], "-n", 2)
		&& ft_strlen(cmd->args[1]) == 2)
		return (0);
	else
	{
		message = join_message(input, cmd);
		printf("%s", message);
		if (ft_strncmp(cmd->args[1], "-n", 2))
			printf("\n");
	}
	return (0);
}

char	*join_message(t_input *input, t_cmd_lst *cmd)
{
	int		i;
	int		option;
	char	*message;

	i = 0;
	option = NO;
	message = NULL;
	if (!ft_strncmp(cmd->args[1], "-n", 2) && ft_strlen(cmd->args[1]) == 2)
		option = YES;
	if (!ft_strncmp(cmd->args[1], "-n", 2) && ft_strlen(cmd->args[1]) == 2)
		i++;
	while (++i < cmd->n_args)
	{
		if (i == 1 || (i == 2 && option == YES))
			message = ft_strdup(input, cmd->args[i]);
		else
			message = ft_strjoin(input, message, cmd->args[i]);
		input->gb->type = GARBAGE;
		if (i != cmd->n_args - 1)
		{
			message = ft_strjoin(input, message, " ");
			input->gb->type = GARBAGE;
		}
	}
	return (message);
}

void	print_message(char *message)
{
	size_t	i;
	char	c;

	i = -1;
	while (++i < ft_strlen(message))
	{
		if (ft_strchr("\'\"", message[i]))
		{
			c = message[i];
			while (message[i] && message[++i] != c)
				write(1, &message[i], 1);
		}
		if (!ft_strchr("\'\"", message[i]))
			write(1, &message[i], 1);
	}
}
