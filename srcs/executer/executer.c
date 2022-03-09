/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:51:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/09 19:07:10 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	executer(char **envp, t_input *input, t_cmd_lst **lst_node)
{
	int	status;

	status = 0;
	path_manager(envp, input, lst_node);
	open_files(lst_node);
	open_all_pipes(lst_node);
	convert_env_tab(input);
	if (input->n_cmd == 1 && find_built_in((*lst_node)->cmd_name) == BUILT_IN)
	{
		int i = -1;
		dup2(STDOUT_FILENO, STDOUT_FILENO);
		input->process = safe_malloc(sizeof(pid_t), input->n_cmd);
		handle_input_redir(*lst_node);
		while (++i < (*lst_node)->n_output_redir)
		{
			printf("here\n");
			dup2((*lst_node)->fd_output[i], STDOUT_FILENO);
		}
		exec_built_in(input, *lst_node);
		// dup2(0, STDIN_FILENO);
		// dup2(1, STDOUT_FILENO);
		waitpid(input->process[0], &status, 0);
		status = (WEXITSTATUS(status));
	}
	else
		status = pipex(envp, input, lst_node);
	printf(" - - - - - - - - - - - - - - - - - - - \n");
	return (status);
}
