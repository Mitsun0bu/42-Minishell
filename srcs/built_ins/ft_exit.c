/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:51:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/25 17:31:09 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_exit(t_input *input, t_cmd_lst *cmd)
{
	ft_putstr_fd("exit\n", 2);
	if (cmd->args[1])
	{
		print_err(255, NULL, "exit", "use exit with no argument");
		clear_all_gb(&input->gb);
		exit(255);
	}
	exit(0);
}
