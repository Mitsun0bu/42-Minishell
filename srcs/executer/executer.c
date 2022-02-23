/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:51:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/23 18:43:08 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	executer(char **envp, t_input *input, t_cmd_lst **lst_node)
{
	path_manager(envp, input, lst_node);
	if (input->n_cmd == 1)
		exec_single_cmd(envp, input, lst_node);
	else
		exec_multi_cmd(input, lst_node);
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
	return ;
}

int	exec_multi_cmd(t_input *input, t_cmd_lst **lst_node)
{
	t_pip	pip;

	ft_memset(&pip, 0, sizeof(pip));
	open_files(lst_node);
	create_pipes(input, &pip);
	pipex(input, lst_node, &pip);
	close_pipes(input, &pip);
	ft_free(pip.fd_tab);
	return (0);
}

int	create_pipes(t_input *input, t_pip *pip)
{
	int	i;

	i = -1;
	pip->n_fd = (input->n_cmd - 1) * 2;
	pip->fd_tab = safe_malloc(sizeof(int), pip->n_fd);
	while(++i < input->n_cmd - 1)
	{
		if (pipe(&pip->fd_tab[i * 2]) == -1)
		{
			perror("");
			exit(1);
		}
	}
	return (0);
}

int	close_pipes(t_input *input, t_pip *pip)
{

}

int	pipex(t_input *input, t_cmd_lst **lst_node, t_pip *pip)
{
	int	i;

	pip->task = safe_malloc(sizeof(pid_t), pip->n_fd);
	i = -1;
	while (++i < input->n_cmd - 1)
	{
		pip->task[i] = fork();
		if(i = 0 && pip->task[i] == 0)
		{

		}
		// else if ()
		// {

		// }
		else if (i = input->n_cmd - 1 && pip->task[i] == 0)
		{

		}
	}
}