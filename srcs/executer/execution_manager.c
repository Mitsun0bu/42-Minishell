/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:41:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/08 12:08:33 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	exec_first_cmd(char **envp, t_input *input, t_cmd_lst *lst_node)
{
	int	redir;

	printf("| \n");
	printf("| EXEC FIRST CMD\n");
	redir = 0;
	if (lst_node->n_input_redir)
		redir = redir_input(lst_node);
	if (input->last_output_redir_tab[0] == TRUNC_OUTPUT)
	{
		if (lst_node->n_app_output_redir)
			redir = redir_app_output(lst_node);
		redir = redir_output(lst_node);
	}
	else if (input->last_output_redir_tab[0] == APP_OUTPUT)
	{
		if (lst_node->n_app_output_redir)
			redir = redir_output(lst_node);
		redir = redir_app_output(lst_node);
	}
	if (!redir)
		if (lst_node->next != NULL)
			dup2(lst_node->pipe_fd_tab[1], STDOUT_FILENO);
	close_all_pipes(lst_node);
	if (ft_strncmp(lst_node->cmd_name, "./minishell", 11) == 0)
		printf("failed\n");
	if (lst_node->valid_path)
		exit(exec_single_cmd(envp, input, lst_node));
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
	if (input->last_output_redir_tab[lst_node->cmd_index] == TRUNC_OUTPUT)
	{
		if (lst_node->n_app_output_redir)
			redir_out = redir_app_output(lst_node);
		redir_out = redir_output(lst_node);
	}
	else if (input->last_output_redir_tab[lst_node->cmd_index] == APP_OUTPUT)
	{
		if (lst_node->n_app_output_redir)
			redir_out = redir_output(lst_node);
		redir_out = redir_app_output(lst_node);
	}
	if (!redir_in)
		dup2(lst_node->previous->pipe_fd_tab[0], STDIN_FILENO);
	if (!redir_out)
		dup2(lst_node->pipe_fd_tab[1], STDOUT_FILENO);
	close_all_pipes(lst_node);
	if (lst_node->valid_path)
		exit(exec_single_cmd(envp, input, lst_node));
}

void	exec_last_cmd(char **envp, t_input *input, t_cmd_lst *lst_node)
{
	int	redir_in;
	int	redir_out;

	printf("| \n");
	printf("| EXEC LAST CMD\n");
	redir_in = 0;
	redir_out = 0;
	if (lst_node->n_input_redir)
		redir_in = redir_input(lst_node);
	if (input->last_output_redir_tab[lst_node->cmd_index] == TRUNC_OUTPUT)
	{
		if (lst_node->n_app_output_redir)
			redir_out = redir_app_output(lst_node);
		redir_out = redir_output(lst_node);
	}
	else if (input->last_output_redir_tab[lst_node->cmd_index] == APP_OUTPUT)
	{
		if (lst_node->n_app_output_redir)
			redir_out= redir_output(lst_node);
		redir_out = redir_app_output(lst_node);
	}
	if (!redir_in)
		dup2(lst_node->previous->pipe_fd_tab[0], STDIN_FILENO);
	close_all_pipes(lst_node);
	if (lst_node->valid_path)
		exit(exec_single_cmd(envp, input, lst_node));
}

int	exec_single_cmd(char **envp, t_input *input, t_cmd_lst *lst_node)
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
		status = ft_exit();
	else if (!ft_strncmp(lst_node->cmd_name, "export", 6) && !lst_node->cmd_name[6])
		status = ft_export(input, lst_node);
	else if (!ft_strncmp(lst_node->cmd_name, "unset", 5) && !lst_node->cmd_name[5])
		status = ft_unset(input);
	else
		execve(lst_node->valid_path, lst_node->cmd_args, envp);
	return (status);
}
