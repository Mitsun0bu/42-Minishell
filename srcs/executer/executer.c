/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:51:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/22 15:58:55 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	prepare_exec(t_input *input, t_cmd_lst *cmd);
static void	launch_exec(t_input *input, t_cmd_lst *cmd);

void	executer(t_input *input, t_cmd_lst *cmd)
{
	if (prepare_exec(input, cmd) == FAILED)
		return ;
	launch_exec(input, cmd);
}

static int	prepare_exec(t_input *input, t_cmd_lst *cmd)
{
	if (handle_heredocs(input, cmd) == FAILED)
		return (FAILED);
	if (open_all_pipes(cmd) == FAILED)
	{
		close_all_pipes(cmd);
		return (FAILED);
	}
	return (SUCCESS);
}

static void	launch_exec(t_input *input, t_cmd_lst *cmd)
{
	if (open_all_files(input, cmd) == FAILED)
		g_status = 1;
	if (input->n_cmd == 1 && cmd_is_built_in(cmd->name) == YES)
	{
		set_stdout(input, cmd);
		g_status = exec_built_in(input, cmd);
		dup2(STDIN_FILENO, STDOUT_FILENO);
	}
	else
		g_status = pipe_exec(input, cmd);
}
