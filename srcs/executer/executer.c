/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:51:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/08 18:24:59 by llethuil         ###   ########lyon.fr   */
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
	if (input->n_cmd == 1)
	{
		// if (!ft_strncmp((*lst_node)->cmd_name, "./minishell", 11)
		// 	&& !(*lst_node)->cmd_name[11])
		// 	status = exec_minishell(envp, input, (*lst_node));
		if (find_built_in((*lst_node)->cmd_name) == BUILT_IN)
			status = exec_single_cmd(envp, input, (*lst_node));
	}
	if ((input->n_cmd == 1 && find_built_in((*lst_node)->cmd_name) != BUILT_IN)
		|| input->n_cmd > 1)
		status = pipex(envp, input, lst_node);
	printf(" - - - - - - - - - - - - - - - - - - - \n");
	return (0);
}
