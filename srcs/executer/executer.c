/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:51:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/22 18:12:03 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	executer(char **av, char **envp, t_input *input, t_cmd_lst **lst_head)
{
	path_manager(av, envp, input, lst_head);
	if (input->n_cmd == 1)
		exec_cmd(input, av, envp);
	else
		pipex(input, lst_head);
	return (0);
}

void	exec_cmd(t_input *input, char **av, char **envp)
{
	(void)av;
	(void)envp;
	(void)input;
	// if (ft_strncmp(input->cmd_exec_tab[0][0], "cd", 2) == 0)
	// 	ft_cd(input);
	// else if (ft_strncmp(input->cmd_exec_tab[0][0], "echo", 4) == 0)
	// 	ft_echo(input);
	// else if (ft_strncmp(input->cmd_exec_tab[0][0], "env", 3) == 0)
	// 	ft_env(input);
	// else if (ft_strncmp(input->cmd_exec_tab[0][0], "exit", 4) == 0)
	// 	ft_exit(input);
	// else if (ft_strncmp(input->cmd_exec_tab[0][0], "export", 6) == 0)
	// 	ft_export(input);
	// else if (ft_strncmp(input->cmd_exec_tab[0][0], "pwd", 3) == 0)
	// 	ft_pwd(input);
	// else if (ft_strncmp(input->cmd_exec_tab[0][0], "unset", 5) == 0)
	// 	ft_unset(input);
	// else
	// {

	// }
	return ;
}

int	pipex(t_input *input, t_cmd_lst **lst_head)
{
	t_pip	pip;

	ft_memset(&pip, 0, sizeof(pip));
	open_files(lst_head);
	create_pipes(input, &pip);
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
	// TEST //
	i = -1;
	while(++i < input->n_cmd)
		printf("fd_tab[%d] = %d\n", i, pip->fd_tab[i]);
	return (0);
}