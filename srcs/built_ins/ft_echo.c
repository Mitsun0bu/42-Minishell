/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:55:57 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/27 17:35:27 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char	*join_message(t_input *input, t_cmd_lst *cmd);
static int	skip_options(t_cmd_lst *cmd);

int	ft_echo(t_input *input, t_cmd_lst *cmd)
{
	char	*message;

	message = NULL;
	g_status = 0;
	if (cmd->n_args == 1)
	{
		printf("\n");
		return (g_status);
	}
	if (cmd->n_args == 2)
		if (ft_strcmp(cmd->args[1], "-n") == SUCCESS)
			return (g_status);
	message = join_message(input, cmd);
	printf("%s", message);
	if (ft_strcmp(cmd->args[1], "-n") == FAILED)
		printf("\n");
	return (g_status);
}

static char	*join_message(t_input *input, t_cmd_lst *cmd)
{
	int		i;
	char	*message;

	message = ft_strdup(input, "");
	input->gb->type = GARBAGE;
	i = skip_options(cmd) - 1;
	while (++i < cmd->n_args)
	{
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

static int skip_options(t_cmd_lst *cmd)
{
	int i;

	i = 1;
	while (ft_strcmp(cmd->args[i], "-n") == SUCCESS)
		i++;
	return (i);
}
