/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:51:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/01 14:25:07 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	executer(char **envp, t_input *input, t_cmd_lst **lst_node)
{
	int	status;
	path_manager(envp, input, lst_node);
	// if (input->n_cmd == 1)
	// 	exec_single_cmd(envp, input, lst_node);
	// else
		status = exec_multi_cmd(envp, input, lst_node);
	return (0);
}

void	exec_single_cmd(char **envp, t_input *input, t_cmd_lst **lst_node)
{
	if (ft_strncmp((*lst_node)->cmd_name, "cd", 2) == 0)
		ft_cd(*lst_node);
	else if (ft_strncmp((*lst_node)->cmd_name, "echo", 4) == 0)
		ft_echo(*lst_node);
	else if (ft_strncmp((*lst_node)->cmd_name, "pwd", 3) == 0)
		ft_pwd(*lst_node);
	else if (ft_strncmp((*lst_node)->cmd_name, "env", 3) == 0)
		ft_env(input);
	else if (ft_strncmp((*lst_node)->cmd_name, "exit", 4) == 0)
		ft_exit();
	// else if (ft_strncmp(input->cmd_exec_tab[0][0], "export", 6) == 0)
	// 	ft_export(input);
	// else if (ft_strncmp(input->cmd_exec_tab[0][0], "unset", 5) == 0)
	// 	ft_unset(input);
	else
	{
		execve((*lst_node)->valid_path, (*lst_node)->cmd_args, envp);
	}
}

int	exec_multi_cmd(char **envp, t_input *input, t_cmd_lst **lst_node)
{
	int	status;

	status = 0;
	open_files(lst_node);
	open_all_pipes(lst_node);
	status = pipex(envp, input, lst_node);
	printf(" - - - - - - - - - - - - - - - - - - - \n");
	return (status);
}

int	pipex(char **envp, t_input *input, t_cmd_lst **lst_node)
{
	int			i;
	t_cmd_lst	*start;
	int			status;

	printf(" - - - - - - - - PIPEX - - - - - - - - \n");
	input->process = safe_malloc(sizeof(pid_t), input->n_cmd);
	i = -1;
	start = *lst_node;
	while(++i < input->n_cmd)
	{
		input->process[i] = fork();
		check_fork_error(input->process[i]);
		if (i == 0 && input->process[i] == 0)
			exec_first_cmd(envp, *lst_node);
		else if (i != 0 && i != input->n_cmd - 1 && input->process[i] == 0)
			exec_a_cmd(envp, *lst_node);
		else if (i == input->n_cmd - 1 && input->process[i] == 0)
			exec_last_cmd(envp, *lst_node);
		*lst_node = (*lst_node)->next;
	}
	*lst_node = start;
	close_all_pipes(*lst_node);
	status = wait_all_processes(input);
	return (WEXITSTATUS(status));
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

	i = -1;
	while (++i < input->n_cmd)
	{
		waitpid(input->process[i], &status, 0);
		printf("| STATUS PROCESS %d = %d\n", i, status);
	}
	return (status);
}

void	exec_first_cmd(char **envp, t_cmd_lst *lst_node)
{
	printf("| \n");
	printf("| EXEC FIRST CMD\n");
	dup2(lst_node->pipe_fd_tab[1], STDOUT_FILENO);
	close_all_pipes(lst_node);
	if (lst_node->valid_path)
		execve(lst_node->valid_path, lst_node->cmd_args, envp);
}

void	exec_a_cmd(char **envp, t_cmd_lst *lst_node)
{
	printf("| EXEC A CMD\n");
	(void)envp;
	(void)lst_node;
}

void	exec_last_cmd(char **envp, t_cmd_lst *lst_node)
{
	printf("| \n");
	printf("| EXEC LAST CMD\n");
	dup2(lst_node->previous->pipe_fd_tab[0], STDIN_FILENO);
	close_all_pipes(lst_node);
	if (lst_node->valid_path)
		execve(lst_node->valid_path, lst_node->cmd_args, envp);
}
