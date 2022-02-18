/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:51:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/18 16:12:41 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	executer(char **av, char **envp, t_input *input, t_cmd_lst **lst_head)
{
	t_cmd_lst	*start;

	start = *lst_head;
	get_paths_tab(envp, input);
	while (*lst_head)
	{
		(*lst_head)->valid_path = strdup(assign_path(av, "test", input, *lst_head));
		*lst_head = (*lst_head)->next;
	}
	*lst_head = start;
	exec_cmd(input, av, envp);
	return (0);
}

void	get_paths_tab(char **envp, t_input	*input)
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
		free(buff);
	}
	free(paths_line);
}

char	*assign_path(char **av, char *arg, t_input *input, t_cmd_lst *lst_head)
{
	int		i;
	char	*path;

	i = -1;
	while (input->paths_tab[++i])
	{
		(void)arg;
		// if (access(arg, F_OK) == 0)
		// 	return (arg);
		path = ft_strjoin(input->paths_tab[i], lst_head->cmd_name);
		printf("path[%d] before test: %s\n",i, path);
		if (access(path, F_OK) == 0)
		{
			printf("path[%d]: %s, has been selected\n", i, path);
			return (path);
		}
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

void	exec_cmd(t_input *input, char **av, char **envp)
{
	(void)av;
	(void)envp;
	(void)input;
	printf("exec test\n");
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