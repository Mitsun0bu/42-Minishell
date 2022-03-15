/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:55:57 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/15 11:27:19 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_echo(t_cmd_lst *cmd)
{
	char	*message;

	message = NULL;
	if (!cmd->args[1])
		printf("\n");
	else if (!cmd->args[2]
		&& !ft_strncmp(cmd->args[1], "-n", 2))
		return (0);
	else
	{
		message = join_message(cmd, message);
		print_message(message);
		ft_free(message);
		if (ft_strncmp(cmd->args[1], "-n", 2))
			printf("\n");
	}
	return (0);
}

char	*join_message(t_cmd_lst *cmd, char *message)
{
	int		i;

	i = 0;
	if (!ft_strncmp(cmd->args[1], "-n", 2))
		i++;
	while (++i < cmd->n_args)
	{
		if ((i == 1 && ft_strncmp(cmd->args[1], "-n", 2) != 0)
			|| (i == 2 && !ft_strncmp(cmd->args[1], "-n", 2)))
			add_first_word_to_message(cmd, &message, &i);
		if (i != 1 || (i != 2 && !ft_strncmp(cmd->args[1], "-n", 2)))
			add_next_words_to_message(cmd, &message, &i);
	}
	return (message);
}

void	add_first_word_to_message(t_cmd_lst *cmd, char **message, int *i)
{
	char	*buffer;

	*message = ft_strdup(cmd->args[*i]);
	buffer = *message;
	*message = ft_strjoin(buffer, " ");
	ft_free(buffer);
	if (*i == 2)
		(*i)++;
}

void	add_next_words_to_message(t_cmd_lst *cmd, char **message, int *i)
{
	char	*buffer;

	buffer = *message;
	*message = ft_strjoin(buffer, cmd->args[*i]);
	ft_free(buffer);
	if (*i != cmd->n_args - 1)
	{
		buffer = *message;
		*message = ft_strjoin(buffer, " ");
		ft_free(buffer);
	}
}

void	print_message(char *message)
{
	size_t	i;

	i = -1;
	while (++i < ft_strlen(message))
	{
		if (message[i] == '\'')
		{
			while (message[++i] != '\'')
				write(1, &message[i], 1);
			if (message[i] == '\'')
				i ++;
		}
		else if (message[i] == '\"')
		{
			while (message[++i] != '\"')
				write(1, &message[i], 1);
			if (message[i] == '\"')
				i ++;
		}
		write(1, &message[i], 1);
	}
}
