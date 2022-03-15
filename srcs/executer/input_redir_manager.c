/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redir_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:07:06 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/15 12:14:55 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	handle_input_redir(t_cmd_lst *cmd)
{
	int	i;

	i = -1;
	if (cmd->n_input_redir)
	{
		while (++i < cmd->n_input_redir)
			dup2(cmd->fd_input[i], STDIN_FILENO);
	}
	return (i);
}
// int	dup_redir_input(t_cmd_lst *cmd)
// {

// 	while (++i < cmd->n_input_redir)
// 			dup2(cmd->fd_input[i], STDIN_FILENO);
// 	return (1);
// }