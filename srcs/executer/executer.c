/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:51:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/20 09:41:38 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	executer(t_input *input, t_cmd_lst *cmd)
{
	if (handle_heredocs(input, cmd) == FAILED)
		return ;
	if (open_all_files(input, cmd) == FAILED)
		g_status = 1;
	if (open_all_pipes(cmd) == FAILED)
	{
		close_all_pipes(cmd);
		return ;
	}
	if (input->n_cmd == 1 && is_built_in(cmd->name) == YES)
	{
		handle_outfile(input, cmd);
		g_status = exec_built_in(input, cmd);
		dup2(STDIN_FILENO, STDOUT_FILENO);
	}
	else
		g_status = pipex(input, cmd);
}
