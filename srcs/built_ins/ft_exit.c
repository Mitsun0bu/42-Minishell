/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:51:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/04 17:58:13 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static long long	check_exit_arg(char *arg);
static int			arg_is_numeric(char *arg);

int	ft_exit(t_input *input, t_cmd_lst *cmd)
{
	char		*arg;
	long long	check_result;

	arg = NULL;
	check_result = 0;
	if (cmd->n_args > 2)
	{
		ft_putstr_fd("exit\n", 2);
		print_err(1, NULL, "exit", "too many arguments");
		return (g_status);
	}
	if (cmd->args[1])
	{
		arg = ft_strtrim(input, cmd->args[1], " \t\n\v\f\r");
		input->gb->type = GARBAGE;
		check_result = check_exit_arg(arg);
		if (check_result == FAILED)
			return (g_status);
		else
			g_status = (int)check_result % 256;
	}
	else
		g_status = check_result % 256;
	ft_putstr_fd("exit\n", 2);
	return (g_status);
}

static long long	check_exit_arg(char *arg)
{
	long long	numeric_arg;

	numeric_arg = 0;
	if (arg_is_numeric(arg) == NO)
		return (FAILED);
	numeric_arg = (long long)ft_atoi(arg);
	if (numeric_arg == OVERFLOW)
	{
		ft_putstr_fd("exit\n", 2);
		print_err(255, NULL, "exit", "numeric argument required");
		return (FAILED);
	}
	return (numeric_arg);
}

static int	arg_is_numeric(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (i == 0 && (arg[0] == '+' || arg[0] == '-'))
			i ++;
		if (ft_isdigit(arg[i]) == NO)
		{
			ft_putstr_fd("exit\n", 2);
			print_err(255, NULL, "exit", "numeric argument required");
			return (NO);
		}
	}
	return (YES);
}
