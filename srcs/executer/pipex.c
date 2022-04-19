/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:31:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/19 10:40:05 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// printf(" - - - - - - - - PIPEX - - - - - - - - \n");
int	pipex(t_input *input, t_cmd_lst *cmd)
{
	int			i;
	t_cmd_lst	*start;

	input->process = ft_malloc(input, sizeof(pid_t), input->n_cmd);
	input->gb->type = INPUT_STRUCT;
	tcsetattr(STDIN_FILENO, TCSANOW, &input->old_term);
	signal(SIGINT, signal_handler_exec);
	i = -1;
	start = cmd;
	while (++i < input->n_cmd)
	{
		input->process[i] = fork();
		check_fork_error(input->process[i]);
		if (i == 0 && input->process[i] == CHILD)
			exec_first_cmd(input, cmd);
		else if (i != 0 && i != input->n_cmd - 1 && input->process[i] == CHILD)
			exec_mid_cmd(input, cmd);
		else if (i == input->n_cmd - 1 && input->process[i] == CHILD)
			exec_last_cmd(input, cmd);
		cmd = cmd->next;
	}
	cmd = start;
	close_all_pipes(cmd);
	close_all_files(cmd);
	input->status = wait_all_processes(input);
	return (WEXITSTATUS(input->status));
}
