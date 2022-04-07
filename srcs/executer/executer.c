/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:51:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/07 11:59:54 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	executer(t_input *input, t_cmd_lst *cmd)
{
	path_manager(input, cmd);
	if (open_files(input, cmd) == -1)
		return ;
	if (open_all_pipes(cmd) == -1)
		return ;
	if (handle_heredocs(input, cmd) == FAILED)
		return ;
	if (input->n_cmd == 1 && find_built_in(cmd->name) == BUILT_IN)
	{
		handle_outfile(input, cmd);
		input->status = exec_built_in(input, cmd);
		dup2(STDIN_FILENO, STDOUT_FILENO);
	}
	else
		input->status = pipex(input, cmd);
	// printf("- - - - - - - - - - - - - - - - - - - \n");
}
