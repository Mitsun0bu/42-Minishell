/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:41:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/19 11:14:31 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// printf("| \n");
// printf("| EXEC FIRST CMD\n");
// printf("| cmd index = %d\n", cmd->i);
void	exec_first_cmd(t_input *input, t_cmd_lst *cmd)
{
	if (path_manager(input, cmd) == FAILED && is_built_in(cmd->name) == NO)
		exit (input->status);
	set_stdin(input, cmd);
	set_stdout(input, cmd);
	close_all_pipes(cmd);
	if (is_built_in(cmd->name) == YES)
	{
		input->status = exec_built_in(input, cmd);
		exit(input->status);
	}
	else if (cmd->name && cmd->valid_path)
		execve(cmd->valid_path, cmd->args, convert_env_tab(input));
	else
		exit(0);
}

// printf("| \n");
// printf("| EXEC A CMD\n");
// printf("| cmd index = %d\n", cmd->i);
void	exec_mid_cmd(t_input *input, t_cmd_lst *cmd)
{
	if (path_manager(input, cmd) == FAILED && is_built_in(cmd->name) == NO)
		exit (input->status);
	set_stdin(input, cmd);
	set_stdout(input, cmd);
	close_all_pipes(cmd);
	if (is_built_in(cmd->name) == YES)
	{
		input->status = exec_built_in(input, cmd);
		exit(input->status);
	}
	else if (cmd->name && cmd->valid_path)
		execve(cmd->valid_path, cmd->args, convert_env_tab(input));
	else
		exit(0);
}

// printf("| \n");
// printf("| EXEC LAST CMD\n");
// printf("| cmd index = %d\n", cmd->i);
void	exec_last_cmd(t_input *input, t_cmd_lst *cmd)
{
	if (path_manager(input, cmd) == FAILED && is_built_in(cmd->name) == NO)
		exit (input->status);
	set_stdin(input, cmd);
	set_stdout(input, cmd);
	close_all_pipes(cmd);
	if (is_built_in(cmd->name) == YES)
	{
		input->status = exec_built_in(input, cmd);
		exit(input->status);
	}
	else if (cmd->name && cmd->valid_path)
		execve(cmd->valid_path, cmd->args, convert_env_tab(input));
	else
		exit(0);
}

int	exec_built_in(t_input *input, t_cmd_lst *cmd)
{
	if (!ft_strncmp(cmd->name, "cd", 2) && !cmd->name[2])
		return (ft_cd(input, cmd));
	else if (!ft_strncmp(cmd->name, "echo", 4) && !cmd->name[4])
		return (ft_echo(input, cmd));
	else if (!ft_strncmp(cmd->name, "pwd", 3) && !cmd->name[3])
		return (ft_pwd());
	else if (!ft_strncmp(cmd->name, "env", 3) && !cmd->name[3])
		return (ft_env(input));
	else if (!ft_strncmp(cmd->name, "exit", 4) && !cmd->name[4])
		return (ft_exit(input, cmd));
	else if (!ft_strncmp(cmd->name, "export", 6) && !cmd->name[6])
		return (ft_export(input, cmd));
	else if (!ft_strncmp(cmd->name, "unset", 5) && !cmd->name[5])
		return (ft_unset(input, cmd));
	else
		return (FAILED);
}
