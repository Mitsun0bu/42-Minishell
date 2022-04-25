/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:31:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/21 17:50:19 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	child_exec_cmd(t_input *input, t_cmd_lst *cmd);
static void	finish_exec(t_input *input, t_cmd_lst *cmd);
static int	wait_all_processes(t_input *input);

int	pipe_exec(t_input *input, t_cmd_lst *cmd)
{
	int			i;
	t_cmd_lst	*start;

	input->process = ft_malloc(input, sizeof(pid_t), input->n_cmd);
	input->gb->type = INPUT_STRUCT;
	set_termios(input, UNSET);
	set_signals(EXEC);
	i = -1;
	start = cmd;
	while (++i < input->n_cmd)
	{
		input->process[i] = fork();
		check_fork_error(input->process[i]);
		if (input->process[i] == CHILD)
			child_exec_cmd(input, cmd);
		cmd = cmd->next;
	}
	cmd = start;
	finish_exec(input, cmd);
	set_termios(input, YES);
	set_signals(MAIN);
	return (WEXITSTATUS(g_status));
}

static void	child_exec_cmd(t_input *input, t_cmd_lst *cmd)
{
	if (get_path(input, cmd) == FAILED && cmd_is_built_in(cmd->name) == NO)
		exit (g_status);
	if (set_stdin(input, cmd) == FAILED)
		exit (g_status);
	set_stdout(input, cmd);
	close_all_pipes(cmd);
	if (cmd_is_built_in(cmd->name) == YES)
	{
		g_status = exec_built_in(input, cmd);
		exit(g_status);
	}
	else if (cmd->name && cmd->valid_path)
		execve(cmd->valid_path, cmd->args, convert_env_tab(input));
	else
		exit(0);
}

static void	finish_exec(t_input *input, t_cmd_lst *cmd)
{
	close_all_pipes(cmd);
	close_all_files(cmd);
	// signal(SIGINT, SIG_IGN);
	signal(SIGINT, signal_handler_parent);
	g_status = wait_all_processes(input);
}

static int	wait_all_processes(t_input *input)
{
	int	status;
	int	i;

	status = 0;
	i = -1;
	while (++i < input->n_cmd)
		waitpid(input->process[i], &status, 0);
	return (status);
}
