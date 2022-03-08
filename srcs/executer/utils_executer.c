/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_executer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:32:59 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/08 12:08:25 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	find_built_in(char *cmd_name)
{
	if (!ft_strncmp(cmd_name, "./minishell", 11) && !cmd_name[11])
		return (2);
	if (!ft_strncmp(cmd_name, "cd", 2) && !cmd_name[2])
		return (BUILT_IN);
	else if (!ft_strncmp(cmd_name, "echo", 4) && !cmd_name[4])
		return (BUILT_IN);
	else if (!ft_strncmp(cmd_name, "pwd", 3) && !cmd_name[3])
		return (BUILT_IN);
	else if (!ft_strncmp(cmd_name, "env", 3) && !cmd_name[3])
		return (BUILT_IN);
	else if (!ft_strncmp(cmd_name, "exit", 4) && !cmd_name[4])
		return (BUILT_IN);
	else if (!ft_strncmp(cmd_name, "export", 6) && !cmd_name[6])
		return (BUILT_IN);
	else if (!ft_strncmp(cmd_name, "unset", 5) && !cmd_name[5])
		return (BUILT_IN);
	else
		return (0);
}

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

