/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:32:59 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/01 17:33:22 by llethuil         ###   ########lyon.fr   */
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

	i = -1;
	while (++i < input->n_cmd)
	{
		waitpid(input->process[i], &status, 0);
		printf("| STATUS PROCESS %d = %d\n", i, status);
	}
	return (status);
}