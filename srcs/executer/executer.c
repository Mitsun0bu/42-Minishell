/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:51:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/07 18:44:19 by llethuil         ###   ########lyon.fr   */
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
	if (input->n_cmd == 1 && check_built_in((*lst_node)->cmd_name) == 1)
		status = exec_single_cmd(envp, input, (*lst_node));
	else
		status = pipex(envp, input, lst_node);
	printf(" - - - - - - - - - - - - - - - - - - - \n");
	return (0);
}

int	check_built_in(char *cmd_name)
{
	if (ft_strncmp(cmd_name, "cd", 2) == 0)
		return (1);
	else if (ft_strncmp(cmd_name, "echo", 4) == 0)
		return (1);
	else if (ft_strncmp(cmd_name, "pwd", 3) == 0)
		return (1);
	else if (ft_strncmp(cmd_name, "env", 3) == 0)
		return (1);
	else if (ft_strncmp(cmd_name, "exit", 4) == 0)
		return (1);
	else if (ft_strncmp(cmd_name, "export", 6) == 0)
		return (1);
	else if (ft_strncmp(cmd_name, "unset", 5) == 0)
		return (1);
	else
		return (0);
}
