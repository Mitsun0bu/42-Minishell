/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:51:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/16 13:19:50 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	executer(t_input *input, char **av, char **envp)
{
	exec_cmd(input, av, envp);
	return (0);
}

void	exec_cmd(t_input *input, char **av, char **envp)
{
	(void)av;
	(void)envp;
	if (ft_strncmp(input->cmd_exec_tab[0][0], "cd", 2) == 0)
		ft_cd(input);
	else if (ft_strncmp(input->cmd_exec_tab[0][0], "echo", 4) == 0)
		ft_echo(input);
	else if (ft_strncmp(input->cmd_exec_tab[0][0], "env", 3) == 0)
		ft_env(input);
	else if (ft_strncmp(input->cmd_exec_tab[0][0], "exit", 4) == 0)
		ft_exit(input);
	else if (ft_strncmp(input->cmd_exec_tab[0][0], "export", 6) == 0)
		ft_export(input);
	else if (ft_strncmp(input->cmd_exec_tab[0][0], "pwd", 3) == 0)
		ft_pwd(input);
	else if (ft_strncmp(input->cmd_exec_tab[0][0], "unset", 5) == 0)
		ft_unset(input);
	// else
	// {

	// }
	return ;
}