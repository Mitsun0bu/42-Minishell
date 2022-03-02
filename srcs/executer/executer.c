/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:51:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/02 18:48:16 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	executer(char **envp, t_input *input, t_cmd_lst **lst_node)
{
	int	status;

	path_manager(envp, input, lst_node);
	open_files(lst_node);
	open_all_pipes(lst_node);
	status = pipex(envp, input, lst_node);
	printf(" - - - - - - - - - - - - - - - - - - - \n");
	return (0);
}

void	exec_single_cmd(char **envp, t_input *input, t_cmd_lst *lst_node)
{
	if (ft_strncmp(lst_node->cmd_name, "cd", 2) == 0)
		ft_cd(lst_node);
	// else if (ft_strncmp(lst_node->cmd_name, "echo", 4) == 0)
	// 	ft_echo(lst_node);
	else if (ft_strncmp(lst_node->cmd_name, "pwd", 3) == 0)
		ft_pwd(lst_node);
	else if (ft_strncmp(lst_node->cmd_name, "env", 3) == 0)
		ft_env(input);
	else if (ft_strncmp(lst_node->cmd_name, "exit", 4) == 0)
		ft_exit();
	else if (ft_strncmp(lst_node->cmd_name, "export", 6) == 0)
		ft_export(input);
	else if (ft_strncmp(lst_node->cmd_name, "unset", 5) == 0)
		ft_unset(input);
	else
		execve(lst_node->valid_path, lst_node->cmd_args, envp);
}

void	exec_first_cmd(char **envp, t_input *input, t_cmd_lst *lst_node)
{
	int redir;

	printf("| \n");
	printf("| EXEC FIRST CMD\n");
	redir = 0;
	if (lst_node->n_input_redir)
		redir = redir_input(lst_node);
	if (lst_node->n_output_redir)
		redir = redir_output(lst_node);
	if (lst_node->n_app_output_redir)
		redir = redir_app_output(lst_node);
	if (!redir)
		if (lst_node->next != NULL)
			dup2(lst_node->pipe_fd_tab[1], STDOUT_FILENO);
	close_all_pipes(lst_node);
	if (lst_node->valid_path)
		exec_single_cmd(envp, input, lst_node);
}

void	exec_mid_cmd(char **envp, t_input *input, t_cmd_lst *lst_node)
{
	int	redir_in;
	int	redir_out;

	printf("| \n");
	printf("| EXEC A CMD\n");
	redir_in = 0;
	redir_out = 0;
	if (lst_node->n_input_redir)
		redir_in = redir_input(lst_node);
	if (lst_node->n_output_redir)
		redir_out = redir_output(lst_node);
	if (lst_node->n_app_output_redir)
		redir_out = redir_app_output(lst_node);
	if (!redir_in)
		dup2(lst_node->previous->pipe_fd_tab[0], STDIN_FILENO);
	if (!redir_out)
		dup2(lst_node->pipe_fd_tab[1], STDOUT_FILENO);
	close_all_pipes(lst_node);
	if (lst_node->valid_path)
		exec_single_cmd(envp, input, lst_node);
}

void	exec_last_cmd(char **envp, t_input *input, t_cmd_lst *lst_node)
{
	int	redir;
	printf("| \n");
	printf("| EXEC LAST CMD\n");
	redir = 0;
	if (lst_node->n_input_redir)
		redir = redir_input(lst_node);
	if (lst_node->n_output_redir)
		redir = redir_output(lst_node);
	if (lst_node->n_app_output_redir)
		redir = redir_app_output(lst_node);
	if (!redir)
		dup2(lst_node->previous->pipe_fd_tab[0], STDIN_FILENO);
	close_all_pipes(lst_node);
	if (lst_node->valid_path)
		exec_single_cmd(envp, input, lst_node);
}