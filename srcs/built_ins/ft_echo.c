/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:55:57 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/16 14:31:56 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char	*join_message(t_input *input, t_cmd_lst *cmd);
static int	find_last_option_index(t_cmd_lst *cmd);
static int	arg_is_option(char *arg);

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
	if (ft_strncmp(cmd->args[1], "-n", 2))
		printf("\n");
	return (g_status);
}

static char	*join_message(t_input *input, t_cmd_lst *cmd)
{
	int		i;
	char	*message;

	message = ft_strdup(input, "");
	input->gb->type = GARBAGE;
	i = find_last_option_index(cmd) + 1;
	while (i < cmd->n_args)
	{
		message = ft_strjoin(input, message, cmd->args[i]);
		input->gb->type = GARBAGE;
		if (i != cmd->n_args - 1)
		{
			message = ft_strjoin(input, message, " ");
			input->gb->type = GARBAGE;
		}
		i ++;
	}
	return (message);
}

static int	find_last_option_index(t_cmd_lst *cmd)
{
	int	start;
	int	i_arg;

	start = 0;
	i_arg = 1;
	while (i_arg < cmd->n_args)
	{
		if (i_arg == 1 && arg_is_option(cmd->args[i_arg]) == YES)
		{
			i_arg ++;
			start ++;
		}
		while (arg_is_option(cmd->args[i_arg]) == YES)
		{
			i_arg++;
			start ++;
		}
		if (arg_is_option(cmd->args[i_arg]) == NO)
			break ;
		i_arg ++;
	}
	return (start);
}

static int	arg_is_option(char *arg)
{
	size_t	i;
	int		is_option;

	i = 0;
	is_option = NO;
	if (!arg || arg[0] != '-')
		return (NO);
	i++;
	while (i < strlen(arg))
	{
		if (arg[i] && arg[i] == 'n')
			is_option = YES;
		else if (arg[i] && arg[i] != 'n')
		{
			is_option = NO;
			while (arg[i])
				i++;
			break ;
		}
		i++;
	}
	return (is_option);
}
