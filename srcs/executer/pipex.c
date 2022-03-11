/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:31:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/11 15:03:53 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	pipex(t_input *input, t_cmd_lst **lst_node)
{
	int			i;
	int			status;
	t_cmd_lst	*start;

	printf(" - - - - - - - - PIPEX - - - - - - - - \n");
	input->process = safe_malloc(sizeof(pid_t), input->n_cmd);
	i = -1;
	start = *lst_node;
	while (++i < input->n_cmd)
	{
		input->process[i] = fork();
		check_fork_error(input->process[i]);
		if (i == 0 && input->process[i] == 0)
			exec_first_cmd(input, *lst_node);
		else if (i != 0 && i != input->n_cmd - 1 && input->process[i] == 0)
			exec_mid_cmd(input, *lst_node);
		else if (i == input->n_cmd - 1 && input->process[i] == 0)
			exec_last_cmd(input, *lst_node);
		*lst_node = (*lst_node)->next;
	}
	*lst_node = start;
	close_all_pipes(*lst_node);
	status = wait_all_processes(input);
	return (WEXITSTATUS(status));
}
