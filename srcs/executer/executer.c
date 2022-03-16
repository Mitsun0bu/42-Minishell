/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:51:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/16 17:59:44 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	executer(char **envp, t_input *input, t_cmd_lst **cmd)
{
	int	status;

	status = 0;
	path_manager(envp, input, cmd);
	open_files(cmd);
	open_all_pipes(cmd);
	handle_heredocs_pipes(cmd);
	if (input->n_cmd == 1 && find_built_in((*cmd)->name) == BUILT_IN)
	{
		handle_output_redir(input, *cmd);
		status = exec_built_in(input, *cmd);
		dup2(STDIN_FILENO, STDOUT_FILENO);
	}
	else
		status = pipex(input, cmd);
	printf(" - - - - - - - - - - - - - - - - - - - \n");
	return (status);
}
