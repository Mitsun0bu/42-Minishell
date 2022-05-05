/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:55:57 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/05 15:45:08 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char	*join_message(t_input *input, t_cmd_lst *cmd);
static int	find_last_option_index(t_cmd_lst *cmd);
static int	arg_is_option(char *arg, int *i);

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
	if (find_last_option_index(cmd) == 0)
		printf("\n");
	return (g_status);
}

static char	*join_message(t_input *input, t_cmd_lst *cmd)
{
	int		i;
	char	*message;

	message = ft_strdup(input, "");
	input->gb->type = GARBAGE;
	i = find_last_option_index(cmd);
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

static int	find_last_option_index(t_cmd_lst *cmd)
{
	int	start;
	int	i_arg;
	int	i;

	start = 0;
	i_arg = 1;
	while (i_arg < cmd->n_args)
	{
		i = 0;
		if (cmd->args[i_arg][0] == '-')
		{
			if (arg_is_option(cmd->args[i_arg], &i) == YES)
				start ++;
		}
		i_arg ++;
	}
	return (start);
}

static int	arg_is_option(char *arg, int *i)
{
	int	is_option;

	is_option = NO;
	(*i)++;
	while (arg[(*i)])
	{
		if (arg[(*i)] == 'n')
			is_option = YES;
		else if (arg[(*i)] != 'n')
		{
			is_option = NO;
			while (arg[(*i)])
				(*i)++;
			break ;
		}
		(*i)++;
	}
	return (is_option);
}
