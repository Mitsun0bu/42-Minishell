/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:32:59 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/07 13:52:35 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	check_fork_error(pid_t	process)
{
	if (process < 0)
	{
		perror("");
		exit (1);
	}
}

int	wait_all_processes(t_input *input)
{
	int	status;
	int	i;

	status = 0;
	i = -1;
	while (++i < input->n_cmd)
	{
		waitpid(input->process[i], &status, 0);
		printf("| STATUS PROCESS %d = %d\n", i, status);
	}
	return (status);
}

// int	wait_all_processes(t_input *input, t_cmd_lst **lst_node)
// {
// 	t_cmd_lst	*start;
// 	int			status;
// 	int			i;

// 	start = *lst_node;
// 	status = 0;
// 	i = -1;
// 	while (++i < input->n_cmd)
// 	{
// 		printf("| NODE #%d\n", (*lst_node)->cmd_index);
// 		if(input->process[i] == 0)
// 			printf("I AM A CHILD\n");
// 		if(input->process[i] > 0)
// 			printf("I AM A PARENT\n");
// 		waitpid(input->process[i], &status, 0);
// 		printf("| STATUS PROCESS %d = %d\n", i, status);
// 		*lst_node = (*lst_node)->next;
// 	}
// 	*lst_node = start;
// 	return (status);
// }