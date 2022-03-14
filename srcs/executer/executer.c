/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:51:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/14 19:23:45 by llethuil         ###   ########lyon.fr   */
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
	handle_heredocs(input, *lst_node);
	if (input->n_cmd == 1 && find_built_in((*lst_node)->cmd_name) == BUILT_IN)
	{

		handle_output_redir(input, *lst_node);
		status = exec_built_in(input, *lst_node);
		dup2(STDIN_FILENO, STDOUT_FILENO);
	}
	else
		status = pipex(input, lst_node);
	printf(" - - - - - - - - - - - - - - - - - - - \n");
	return (status);
}
