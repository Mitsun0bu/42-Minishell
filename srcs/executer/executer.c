/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:51:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/24 20:11:56 by llethuil         ###   ########lyon.fr   */
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
		printf("here_2\n");
		execve((*lst_node)->valid_path, (*lst_node)->cmd_args, envp);
	}
}

int	exec_multi_cmd(char **envp, t_input *input, t_cmd_lst **lst_node)
{
	t_cmd_lst	*start;
	int			status;

	start = *lst_node;
	open_files(lst_node);
	while (*lst_node)
	{
		status = pipex(envp, input, *lst_node);
		*lst_node = (*lst_node)->next;
	}
	*lst_node = start;
	return (status);
}

int	pipex(char **envp, t_input *input, t_cmd_lst *lst_node)
{
	int		i;
	int		status;
	pid_t	process[2];

	(void)input;
	i = -1;
	if (pipe(lst_node->pipe_fd_tab) == -1)
	{
		perror("");
		exit (1);
	}
	while (++i < 2)
	{
		process[i] = fork();
		if (process[i] < 0)
		{
			perror("");
			exit (1);
		}
		if (i == 0 && process[i] == 0)
		{
			printf("here_1\n");
			exec_current_cmd(envp, lst_node);
		}
		else if (i == 1 && process[i] == 0)
		{
			printf("here_2\n");
			*lst_node = *lst_node->next;
			exec_current_cmd(envp, lst_node);
		}
	}
	close(lst_node->pipe_fd_tab[0]);
	close(lst_node->pipe_fd_tab[1]);
	waitpid(process[0], &status, 0);
	waitpid(process[1], &status, 0);
	return (WEXITSTATUS(status));
}

void	exec_current_cmd(char **envp, t_cmd_lst *lst_node)
{
	int i;

	i = -1;
	printf("here_3\n");
	if (lst_node->n_input_redir > 0)
	{
		while (++i < lst_node->n_input_redir)
		{
			if (lst_node->cmd_index == 0)
				dup2(lst_node->fd_input[i], STDIN_FILENO);
			else
				dup2(lst_node->fd_input[i], lst_node->previous->pipe_fd_tab[1]);
			close(lst_node->fd_input[i]);
		}
	}
	i = -1;
	if (lst_node->n_output_redir > 0)
	{
		while (++i < lst_node->n_output_redir)
		{
			if (lst_node->next == NULL)
				dup2(lst_node->pipe_fd_tab[1], STDOUT_FILENO);
			else
				dup2(lst_node->pipe_fd_tab[1], lst_node->next->pipe_fd_tab[0]);
			close(lst_node->pipe_fd_tab[1]);
		}
	}
	if (lst_node->valid_path)
		execve(lst_node->valid_path, &lst_node->cmd_name, envp);
}