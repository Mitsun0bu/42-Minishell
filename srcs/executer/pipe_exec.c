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
static void	wait_all_processes(t_input *input);

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
	close_all_pipes(cmd);
	close_all_files(cmd);
	wait_all_processes(input);
	set_termios(input, YES);
	set_signals(MAIN);
	return (g_status);
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

static void	wait_all_processes(t_input *input)
{
	int	status;
	int	i;

	status = 0;
	i = -1;
	while (++i < input->n_cmd)
	{
		waitpid(input->process[i], &status, 0);
		if (WIFSIGNALED(status) && WTERMSIG(status) == 2)
		{
			ft_putstr_fd("\n", 2);
			g_status = 130;
		}
		else if (WIFSIGNALED(status) && WTERMSIG(status) == 3)
		{
			ft_putstr_fd("Quit : 3\n", 2);
			g_status = 131;
		}
		else
			g_status = WEXITSTATUS(status);
	}
}
