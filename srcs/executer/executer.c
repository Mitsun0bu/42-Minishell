/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:51:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/01 18:55:00 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	executer(char **envp, t_input *input, t_cmd_lst **lst_node)
{
	int	status;

	path_manager(envp, input, lst_node);
	status = exec_all_cmd(envp, input, lst_node);
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

int	exec_all_cmd(char **envp, t_input *input, t_cmd_lst **lst_node)
{
	int	status;

	status = 0;
	open_files(lst_node);
	open_all_pipes(lst_node);
	status = pipex(envp, input, lst_node);
	printf(" - - - - - - - - - - - - - - - - - - - \n");
	return (status);
}

void	exec_first_cmd(char **envp, t_cmd_lst *lst_node)
{
	printf("| \n");
	printf("| EXEC FIRST CMD\n");

	// ONGOING

	int	pipe_fd_tab_redir[2];
	int	i = -1;
	while (++i < lst_node->n_output_redir)
	{
		pipe_fd_tab_redir[0] = lst_node->fd_output[i];
		if (lst_node->n_output_redir > 1)
		{
			pipe_fd_tab_redir[0] = lst_node->fd_output[i + 1];
			pipe(pipe_fd_tab_redir);
			dup2(lst_node->fd_output[i + 1], STDOUT_FILENO);
			close(lst_node->fd_output[i + 1]);
		}
		printf("fd_output[%d] = %d\n", i, lst_node->fd_output[i]);
		dup2(pipe_fd_tab_redir[0], STDIN_FILENO);
		close(pipe_fd_tab_redir[0]);
	}

	// ONGOING

	if (lst_node->next != NULL)
		dup2(lst_node->pipe_fd_tab[1], STDOUT_FILENO);
	close_all_pipes(lst_node);
	if (lst_node->valid_path)
		execve(lst_node->valid_path, lst_node->cmd_args, envp);
}

void	exec_mid_cmd(char **envp, t_cmd_lst *lst_node)
{
	printf("| \n");
	printf("| EXEC A CMD\n");
	dup2(lst_node->previous->pipe_fd_tab[0], STDIN_FILENO);
	dup2(lst_node->pipe_fd_tab[1], STDOUT_FILENO);
	close_all_pipes(lst_node);
	if (lst_node->valid_path)
		execve(lst_node->valid_path, lst_node->cmd_args, envp);
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
