/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:51:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/27 13:24:12 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_exit(t_input *input, t_cmd_lst *cmd)
{
	long long	num_arg;

	num_arg = ft_atoi(cmd->args[1]);
	g_status = num_arg % 255;
	printf("num_arg: %lld\n", num_arg);
	printf("g_status in ft_exit: %d\n", g_status);
	ft_putstr_fd("exit\n", 2);

	(void)input;
	// print_err(g_status, NULL, "exit", "use exit with no argument");
	// clear_all_gb(&input->gb);
	return(g_status);
}
