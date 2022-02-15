/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_single_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:51:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/15 19:12:33 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	executer(t_input *input, char **av, char **envp)
{

	if (input->n_cmd == 1)
		exec_single_cmd(input, av, envp);
	else
		exec_multi_cmd(input);
	return (0);
}

void	exec_single_cmd(t_input *input, char **av, char **envp)
{
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
	else
	{
		char *path;
		get_paths_tab(envp, input);
		path = assign_path(av, input->cmd_exec_tab[0][1], input->cmd_exec_tab[0][0], input);
		execve(path, &input->cmd_exec_tab[0][0], envp);
	}
	return ;
}

void	get_paths_tab(char **envp, t_input *input)
{
	int		i;
	char	*paths_line;
	char	*buff;

	i = -1;
	paths_line = NULL;
	while (*envp)
	{
		if (ft_strnstr(*envp, "PATH=", 5) != NULL)
		{
			paths_line = ft_substr(*envp, 5, ft_strlen(*envp));
			break ;
		}
		envp++;
	}
	input->paths_tab = ft_split(paths_line, ':');
	while (input->paths_tab[++i])
	{
		buff = input->paths_tab[i];
		input->paths_tab[i] = ft_strjoin(input->paths_tab[i], "/");
		// free(buff);
	}
	free(paths_line);
}

char	*assign_path(char **av, char *arg, char *cmd_name, t_input *input)
{
	int		i;
	char	*path;

	i = -1;
	while (input->paths_tab[++i])
	{
		if (access(arg, F_OK) == 0)
			return (arg);
		path = ft_strjoin(input->paths_tab[i], cmd_name);
		if (access(path, F_OK) == 0)
			return (path);
		// free(path);
		path = NULL;
	}
	(void)av;
	// if (access(path, F_OK) == -1 && cmd_name == cmd->name_1[0])
	// 	error_handler(av, ERR_CMD_1);
	// if (access(path, F_OK) == -1 && cmd_name == cmd->name_2[0])
	// 	error_handler(av, ERR_CMD_2);
	return (NULL);
}

void	exec_multi_cmd(t_input *input)
{
	(void)input;
	// implement pipex
}