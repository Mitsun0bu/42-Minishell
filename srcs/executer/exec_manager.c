/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:41:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/16 17:39:04 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	exec_first_cmd(t_input *input, t_cmd_lst *cmd)
{
	printf("| \n");
	printf("| EXEC FIRST CMD\n");
	if (cmd->n_heredoc)
	{
		dup2(cmd->heredoc_pipe[0], STDIN_FILENO);
		close_single_pipe(cmd->heredoc_pipe);
	}
	handle_input_redir(cmd);
	if (handle_output_redir(input, cmd) == -1)
		if (cmd->next != NULL)
			dup2(cmd->cmd_pipe[1], STDOUT_FILENO);
	close_all_pipes(cmd);
	if (find_built_in(cmd->name) == BUILT_IN)
		exit(exec_built_in(input, cmd));
	else if (find_built_in(cmd->name) == PROGRAM)
		exit(exec_program(input, cmd));
	else if (cmd->name)
		execve(cmd->valid_path, cmd->args, convert_env_tab(input));
}

void	exec_mid_cmd(t_input *input, t_cmd_lst *cmd)
{
	printf("| \n");
	printf("| EXEC A CMD\n");
	if (cmd->n_heredoc)
	{
		dup2(cmd->heredoc_pipe[0], STDIN_FILENO);
		close_single_pipe(cmd->heredoc_pipe);
	}
	if (handle_input_redir(cmd) == -1 && !cmd->n_heredoc)
		dup2(cmd->previous->cmd_pipe[0], STDIN_FILENO);
	if (handle_output_redir(input, cmd) == -1)
		dup2(cmd->cmd_pipe[1], STDOUT_FILENO);
	close_all_pipes(cmd);
	if (find_built_in(cmd->name) == BUILT_IN)
		exit(exec_built_in(input, cmd));
	else if (find_built_in(cmd->name) == PROGRAM)
		exit(exec_program(input, cmd));
	else if (cmd->name)
		execve(cmd->valid_path, cmd->args, convert_env_tab(input));
}

void	exec_last_cmd(t_input *input, t_cmd_lst *cmd)
{
	printf("| \n");
	printf("| EXEC LAST CMD\n");
	if (cmd->n_heredoc)
	{
		dup2(cmd->heredoc_pipe[0], STDIN_FILENO);
		close_single_pipe(cmd->heredoc_pipe);
	}
	handle_output_redir(input, cmd);
	if (handle_input_redir(cmd) == -1 && !cmd->n_heredoc)
		dup2(cmd->previous->cmd_pipe[0], STDIN_FILENO);
	close_all_pipes(cmd);
	if (find_built_in(cmd->name) == BUILT_IN)
		exit(exec_built_in(input, cmd));
	else if (find_built_in(cmd->name) == PROGRAM)
		exit(exec_program(input, cmd));
	else if (cmd->name)
		execve(cmd->valid_path, cmd->args, convert_env_tab(input));
	else if (cmd->name == NULL)
		exit(0);
}

int	exec_built_in(t_input *input, t_cmd_lst *cmd)
{
	int	status;

	status = 0;
	if (!ft_strncmp(cmd->name, "cd", 2) && !cmd->name[2])
		status = ft_cd(input, cmd);
	else if (!ft_strncmp(cmd->name, "echo", 4) && !cmd->name[4])
		status = ft_echo(cmd);
	else if (!ft_strncmp(cmd->name, "pwd", 3) && !cmd->name[3])
		status = ft_pwd(cmd);
	else if (!ft_strncmp(cmd->name, "env", 3) && !cmd->name[3])
		status = ft_env(input);
	else if (!ft_strncmp(cmd->name, "exit", 4) && !cmd->name[4])
		status = ft_exit(input);
	else if (!ft_strncmp(cmd->name, "export", 6) && !cmd->name[6])
		status = ft_export(input, cmd);
	else if (!ft_strncmp(cmd->name, "unset", 5) && !cmd->name[5])
		status = ft_unset(input);
	return (status);
}

int	exec_program(t_input *input, t_cmd_lst *cmd)
{
	char	*cwd;
	char	*program_name;
	char	*program_path;
	int		len;
	unsigned long i;

	i = -1;
	cwd = getcwd(NULL, 0);
	len = ft_strlen(cmd->name) - 1;
	program_name = safe_malloc(sizeof(char), len);
	while(cmd->name[++i])
		program_name[i] = cmd->name[i + 1];
	program_path = ft_strjoin(cwd, program_name);
	ft_free((void *)&cwd);
	ft_free((void *)&program_name);
	printf("ret = %d\n", execve(program_path, cmd->args, convert_env_tab(input)));
	return (0);
}
