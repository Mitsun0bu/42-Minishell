/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:51:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/13 10:22:19 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_exit(t_input *input, t_cmd_lst *cmd)
{
	printf("exit\n");
	if (cmd->args[1])
	{
		printf("minishelled: exit: ");
		printf("%s: use exit with no argument\n", cmd->args[1]);
		clear_all_gb(&input->gb);
		exit(255);
	}
	exit(0);
}
