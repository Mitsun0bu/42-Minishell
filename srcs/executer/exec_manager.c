/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:41:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/13 11:52:33 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	exec_first_cmd(t_input *input, t_cmd_lst *cmd)
{
	// printf("| \n");
	// printf("| EXEC FIRST CMD\n");
	// printf("| cmd index = %d\n", cmd->i);
	signal(SIGINT, signal_handler_child);
	if (handle_infile(input, cmd) == FAILED)
		exit (0);
	if (!handle_outfile(input, cmd))
		if (cmd->next != NULL)
			dup2(cmd->cmd_pipe[1], STDOUT_FILENO);
	close_all_pipes(cmd);
	if (find_built_in(cmd->name) == BUILT_IN)
		exit(exec_built_in(input, cmd));
	else if (!input->paths_tab)
		exit(err_return(1, NULL, cmd->name, "No such file or directory"));
	else if (cmd->name && cmd->valid_path)
		execve(cmd->valid_path, cmd->args, convert_env_tab(input));
	else
		exit(0);
}

void	exec_mid_cmd(t_input *input, t_cmd_lst *cmd)
{
	int	handle_infile_result;
	// printf("| \n");
	// printf("| EXEC A CMD\n");
	// printf("| cmd index = %d\n", cmd->i);
	signal(SIGINT, signal_handler_child);
	handle_infile_result = handle_infile(input, cmd);
	if (handle_infile_result == FAILED)
		exit (0);
	else if (!handle_infile_result && cmd->valid_path)
		dup2(cmd->previous->cmd_pipe[0], STDIN_FILENO);
	if (!handle_outfile(input, cmd) && cmd->valid_path)
		dup2(cmd->cmd_pipe[1], STDOUT_FILENO);
	close_all_pipes(cmd);
	if (find_built_in(cmd->name) == BUILT_IN)
		exit(exec_built_in(input, cmd));
	else if (!input->paths_tab)
		exit(err_return(1, NULL, cmd->name, "No such file or directory"));
	else if (cmd->name && cmd->valid_path)
		execve(cmd->valid_path, cmd->args, convert_env_tab(input));
	else
		exit(0);
}

void	exec_last_cmd(t_input *input, t_cmd_lst *cmd)
{
	int	handle_infile_result;
	// printf("| \n");
	// printf("| EXEC LAST CMD\n");
	signal(SIGINT, signal_handler_child);
	handle_infile_result = handle_infile(input, cmd);
	if (handle_infile_result == FAILED)
		exit (0);
	else if (!handle_infile_result)
		dup2(cmd->previous->cmd_pipe[0], STDIN_FILENO);
	handle_outfile(input, cmd);
	close_all_pipes(cmd);
	if (find_built_in(cmd->name) == BUILT_IN)
		exit(exec_built_in(input, cmd));
	else if (!input->paths_tab)
		exit(err_return(1, NULL, cmd->name, "No such file or directory"));
	else if (cmd->name && cmd->valid_path)
		execve(cmd->valid_path, cmd->args, convert_env_tab(input));
	else
		exit(0);
}

int	exec_built_in(t_input *input, t_cmd_lst *cmd)
{
	int	status;

	status = 0;
	if (!ft_strncmp(cmd->name, "cd", 2) && !cmd->name[2])
		status = ft_cd(input, cmd);
	else if (!ft_strncmp(cmd->name, "echo", 4) && !cmd->name[4])
		status = ft_echo(input, cmd);
	else if (!ft_strncmp(cmd->name, "pwd", 3) && !cmd->name[3])
		status = ft_pwd();
	else if (!ft_strncmp(cmd->name, "env", 3) && !cmd->name[3])
		status = ft_env(input);
	else if (!ft_strncmp(cmd->name, "exit", 4) && !cmd->name[4])
		status = ft_exit(input, cmd);
	else if (!ft_strncmp(cmd->name, "export", 6) && !cmd->name[6])
		status = ft_export(input, cmd);
	else if (!ft_strncmp(cmd->name, "unset", 5) && !cmd->name[5])
		status = ft_unset(input);
	return (status);
}

int	exec_program(t_input *input, t_cmd_lst *cmd)
{
	char			*cwd;
	char			*program_name;
	char			*program_path;
	int				len;
	unsigned long	i;

	i = -1;
	cwd = getcwd(NULL, 0);
	len = ft_strlen(cmd->name) - 1;
	program_name = ft_malloc(input, sizeof(char), len);
	input->gb->type = GARBAGE;
	while (cmd->name[++i])
		program_name[i] = cmd->name[i + 1];
	program_path = ft_strjoin(input, cwd, program_name);
	printf("program path = %s\n", program_path);
	input->gb->type = GARBAGE;
	ft_free((void *)&cwd);
	return (0);
}
