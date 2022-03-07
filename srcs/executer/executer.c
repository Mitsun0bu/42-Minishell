/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:51:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/07 17:20:25 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	executer(char **envp, t_input *input, t_cmd_lst **lst_node)
{
	int	status;

	path_manager(envp, input, lst_node);
	open_files(lst_node);
	open_all_pipes(lst_node);
	if (input->n_cmd == 1 && ft_strncmp((*lst_node)->cmd_name, "export", 6) == 0)
		status = ft_export(input, (*lst_node));
	else if (ft_strncmp((*lst_node)->cmd_name, "cd", 2) == 0)
		status = ft_cd(input, (*lst_node));
	else
		status = pipex(envp, input, lst_node);
	printf(" - - - - - - - - - - - - - - - - - - - \n");
	return (0);
}
