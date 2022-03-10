/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:41:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/10 11:12:49 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	exec_first_cmd(char **envp, t_input *input, t_cmd_lst *lst_node)
{
	printf("| \n");
	printf("| EXEC FIRST CMD\n");
	handle_input_redir(lst_node);
	if (!handle_output_redir(input, lst_node))
		if (lst_node->next != NULL)
			dup2(lst_node->pipe_fd_tab[1], STDOUT_FILENO);
	close_all_pipes(lst_node);
	if (find_built_in(lst_node->cmd_name) == BUILT_IN)
		exit(exec_built_in(input, lst_node));
	else if (find_built_in(lst_node->cmd_name) == PROGRAM)
		exit(exec_program(envp, lst_node));
	else
		execve(lst_node->valid_path, lst_node->cmd_args, envp);
}

void	exec_mid_cmd(char **envp, t_input *input, t_cmd_lst *lst_node)
{
	printf("| \n");
	printf("| EXEC A CMD\n");
	if (!handle_input_redir(lst_node))
		dup2(lst_node->previous->pipe_fd_tab[0], STDIN_FILENO);
	if (!handle_output_redir(input, lst_node))
		dup2(lst_node->pipe_fd_tab[1], STDOUT_FILENO);
	close_all_pipes(lst_node);
	if (find_built_in(lst_node->cmd_name) == BUILT_IN)
		exit(exec_built_in(input, lst_node));
	else if (find_built_in(lst_node->cmd_name) == PROGRAM)
		exit(exec_program(envp, lst_node));
	else
		execve(lst_node->valid_path, lst_node->cmd_args, envp);
}

void	exec_last_cmd(char **envp, t_input *input, t_cmd_lst *lst_node)
{
	printf("| \n");
	printf("| EXEC LAST CMD\n");
	handle_output_redir(input, lst_node);
	if (!handle_input_redir(lst_node))
		dup2(lst_node->previous->pipe_fd_tab[0], STDIN_FILENO);
	close_all_pipes(lst_node);
	if (find_built_in(lst_node->cmd_name) == BUILT_IN)
		exit(exec_built_in(input, lst_node));
	else if (find_built_in(lst_node->cmd_name) == PROGRAM)
		exit(exec_program(envp, lst_node));
	else
		execve(lst_node->valid_path, lst_node->cmd_args, envp);
}

int	exec_built_in(t_input *input, t_cmd_lst *lst_node)
{
	int	status;

	status = 0;
	if (!ft_strncmp(lst_node->cmd_name, "cd", 2) && !lst_node->cmd_name[2])
		status = ft_cd(input, lst_node);
	else if (!ft_strncmp(lst_node->cmd_name, "echo", 4) && !lst_node->cmd_name[4])
		status = ft_echo(lst_node);
	else if (!ft_strncmp(lst_node->cmd_name, "pwd", 3) && !lst_node->cmd_name[3])
		status = ft_pwd(lst_node);
	else if (!ft_strncmp(lst_node->cmd_name, "env", 3) && !lst_node->cmd_name[3])
		status = ft_env(input);
	else if (!ft_strncmp(lst_node->cmd_name, "exit", 4) && !lst_node->cmd_name[4])
		status = ft_exit(input);
	else if (!ft_strncmp(lst_node->cmd_name, "export", 6) && !lst_node->cmd_name[6])
		status = ft_export(input, lst_node);
	else if (!ft_strncmp(lst_node->cmd_name, "unset", 5) && !lst_node->cmd_name[5])
		status = ft_unset(input);
	return (status);
}

int	exec_program(char **envp, t_cmd_lst *lst_node)
{
	char	*cwd;
	char	*program_name;
	char	*program_path;
	int		len;
	unsigned long i;

	i = -1;
	cwd = getcwd(NULL, 0);
	len = ft_strlen(lst_node->cmd_name) - 1;
	program_name = safe_malloc(sizeof(char), len);
	while(lst_node->cmd_name[++i])
		program_name[i] = lst_node->cmd_name[i + 1];
	program_path = ft_strjoin(cwd, program_name);
	ft_free (cwd);
	ft_free (program_name);
	execve(program_path, lst_node->cmd_args, envp);
	return (0);
}
