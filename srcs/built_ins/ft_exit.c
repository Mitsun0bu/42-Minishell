/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:51:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/27 19:23:24 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int check_exit_arg(char *arg);

int	ft_exit(t_input *input, t_cmd_lst *cmd)
{
	long	check_result;
	char	*arg;

	check_result = 0;
	arg = NULL;
	if (cmd->args[1])
	{
		arg = ft_strtrim(input, cmd->args[1], " \t\n\v\f\r");
		input->gb->type = GARBAGE;
		check_result = check_exit_arg(arg);
		if (check_result == FAILED)
			g_status = 255;
		else
			g_status = (int)check_result % 256;
	}
	else
		g_status = check_result % 256;
	ft_putstr_fd("exit\n", 2);
	return(g_status);
}

static int check_exit_arg(char *arg)
{
	int			i;
	long		num_arg;

	num_arg = 0;
	i = -1;
	while(arg[++i])
	{
		if (arg[i] == '+' || arg[i] == '-')
			i ++;
		if (ft_isdigit(arg[i]) == NO)
		{
			print_err(g_status, NULL, "exit", "numeric argument required");
			return (FAILED);
		}
	}
	num_arg = ft_atoi(arg);
	if (num_arg == FAILED)
	{
		print_err(g_status, NULL, "exit", "numeric argument required");
		return (FAILED);
	}
	else
		return (num_arg);
}
