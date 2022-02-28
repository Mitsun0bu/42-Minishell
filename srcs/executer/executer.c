/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:51:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/28 19:28:02 by llethuil         ###   ########lyon.fr   */
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
	int			status = 0;
	int 		i = -1;

	start = *lst_node;
	open_files(lst_node);
	while (*lst_node)
	{
		printf(" - - - - - - - - - - - - - - - - - - - - - \n");
		printf("| OPEN PIPE_FD TAB #%d\n", ++i);
		printf("| NODE INDEX = %d\n", (*lst_node)->cmd_index);
		open_pipe((*lst_node)->pipe_fd_tab);
		printf("| PIPE_FD[0] = %d, PIPE_FD[1] = %d\n", (*lst_node)->pipe_fd_tab[0], (*lst_node)->pipe_fd_tab[1]);
		if ((*lst_node)->next == NULL)
			break;
		*lst_node = (*lst_node)->next->next;
		printf(" - - - - - - - - - - - - - - - - - - - - - \n");
	}
	*lst_node = start;
	status = pipex(envp, input, lst_node);
	printf(" - - - - - - - - - - - - - - - - - - - - - \n");
	return (status);
}

int	pipex(char **envp, t_input *input, t_cmd_lst **lst_node)
{
	t_cmd_lst	*start;
	int			status;

	start = *lst_node;
	printf(" - - - - - - - - - - - - - - - - - - - - - \n");
	printf("| PIPEX \n");
	input->process = safe_malloc(sizeof(pid_t), input->n_cmd);
	printf(" - - - - - - - - - - - - - - - - - - - - - \n\n");
	*lst_node = start;
	close_all_pipes(lst_node);
	*lst_node = start;
	status = wait_all_processes(input, lst_node);
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

void	close_all_pipes(t_cmd_lst **lst_node)
{
	int i = -1;
	while (*lst_node)
	{
		printf(" - - - - - - - - - - - - - - - - - - - - - \n");
		printf("| CLOSE PIPE_FD TAB #%d\n", ++i);
		printf("| NODE INDEX = %d\n", (*lst_node)->cmd_index);
		close_pipe((*lst_node)->pipe_fd_tab);
		printf("| PIPE_FD[0] = %d, PIPE_FD[1] = %d\n", (*lst_node)->pipe_fd_tab[0], (*lst_node)->pipe_fd_tab[1]);
		if ((*lst_node)->next == NULL)
			break;
		*lst_node = (*lst_node)->next->next;
		printf(" - - - - - - - - - - - - - - - - - - - - - \n");
	}
}

void	close_pipe(int *pipe_fd_tab)
{
	close(pipe_fd_tab[0]);
	close(pipe_fd_tab[1]);
}

int	wait_all_processes(t_input *input, t_cmd_lst **lst_node)
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
	printf("| EXEC FIRST CMD\n");
}

void	exec_a_cmd(char **envp, t_cmd_lst *lst_node)
{
	printf("| EXEC A CMD\n");
}

void	exec_last_cmd(char **envp, t_cmd_lst *lst_node)
{
	printf("| EXEC LAST CMD\n");
}
