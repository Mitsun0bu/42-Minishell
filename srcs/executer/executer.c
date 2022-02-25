/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:51:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/25 19:29:56 by llethuil         ###   ########lyon.fr   */
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
	t_cmd_lst	*start;
	int			status;

	// TEST
	int	i = -1;
	// TEST

	start = *lst_node;
	open_files(lst_node);
	while (*lst_node)
	{
		printf(" - - - - - - - - - - - - - - - - - - - - - \n");
		printf("| PIPEX CALL #%d\n", ++i);
		printf("| NODE INDEX = %d\n", (*lst_node)->cmd_index);
		status = pipex(envp, input, *lst_node);
		if ((*lst_node)->next->next != NULL)
			*lst_node = (*lst_node)->next->next;
		else
			break;
	}
	*lst_node = start;
	printf(" - - - - - - - - - - - - - - - - - - - - - \n");
	return (status);
}

int	pipex(char **envp, t_input *input, t_cmd_lst *lst_node)
{
	int		status;
	pid_t	process[2];

	(void)input;
	open_pipe(lst_node->pipe_fd_tab);
	process[0] = fork();
	check_fork_error(process[0]);
	if (process[0] == 0)
	{
		if (lst_node->cmd_index == 0)
			exec_first_cmd(envp, lst_node);
		else if (lst_node->cmd_index != 0)
			exec_current_cmd(envp, lst_node);
	}
	process[1] = fork();
	check_fork_error(process[1]);
	if (process[1] == 0)
	{
		if(lst_node->next->next == NULL)
			exec_last_cmd(envp, lst_node);
		else if (lst_node->next->next != NULL)
			exec_next_cmd(envp, lst_node);
	}
	close_pipe(lst_node->pipe_fd_tab);
	waitpid(process[0], &status, 0);
	printf("| STATUS PROCESS 1 = %d\n", status);
	waitpid(process[1], &status, 0);
	printf("| STATUS PROCESS 2 = %d\n", status);
	return (WEXITSTATUS(status));
}

void	open_pipe(int	*pipe_fd_tab)
{
	if (pipe(pipe_fd_tab) == -1)
	{
		perror("");
		exit (1);
	}
}

void	check_fork_error(pid_t	process)
{
	if (process < 0)
	{
		perror("");
		exit (1);
	}
}

void	close_pipe(int *pipe_fd_tab)
{
	close(pipe_fd_tab[0]);
	close(pipe_fd_tab[1]);
}

void	exec_first_cmd(char **envp, t_cmd_lst *lst_node)
{
	if (lst_node->n_input_redir > 0)
		return ;
	if (lst_node->n_output_redir > 0)
		return ;
	dup2(lst_node->pipe_fd_tab[1], STDOUT_FILENO);
	close_pipe(lst_node->pipe_fd_tab);
	if (lst_node->valid_path)
		execve(lst_node->valid_path, lst_node->cmd_args, envp);
}

void	exec_current_cmd(char **envp, t_cmd_lst *lst_node)
{
	(void)envp;
	if (lst_node->n_input_redir > 0)
		return ;
	if (lst_node->n_output_redir > 0)
		return ;
	printf("coucou\n");
}

void	exec_next_cmd(char **envp, t_cmd_lst *lst_node)
{
	(void)envp;
	if (lst_node->n_input_redir > 0)
		return ;
	if (lst_node->n_output_redir > 0)
		return ;
	printf("salut\n");
}

void	exec_last_cmd(char **envp, t_cmd_lst *lst_node)
{
	if (lst_node->n_input_redir > 0)
		return ;
	if (lst_node->n_output_redir > 0)
		return ;
	dup2(lst_node->pipe_fd_tab[0], STDIN_FILENO);
	close_pipe(lst_node->pipe_fd_tab);
	if (lst_node->valid_path)
		execve(lst_node->next->valid_path, lst_node->next->cmd_args, envp);
}