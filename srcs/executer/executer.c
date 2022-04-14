/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:51:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/14 10:59:15 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	executer(t_input *input, t_cmd_lst *cmd)
{
	path_manager(input, cmd);
	if (handle_heredocs(input, cmd) == FAILED)
		return ;
	if (open_files(input, cmd) == FAILED)
		input->status = 1;
	if (open_all_pipes(cmd) == FAILED)
		return ;
	if (input->n_cmd == 1 && is_built_in(cmd->name) == YES)
	{
		handle_outfile(input, cmd);
		input->status = exec_built_in(input, cmd);
		dup2(STDIN_FILENO, STDOUT_FILENO);
	}
	else
		input->status = pipex(input, cmd);
	// printf("- - - - - - - - - - - - - - - - - - - \n");
}
