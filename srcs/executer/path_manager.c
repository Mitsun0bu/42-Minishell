/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:58:04 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/21 15:32:48 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	path_manager(char **envp, t_input *input, t_cmd_lst **cmd)
{
	t_cmd_lst	*start;

	start = *cmd;
	get_paths_tab(envp, input);
	while (*cmd)
	{
		if (!(*cmd)->name)
			(*cmd)->valid_path = NULL;
		else if (ft_strncmp((*cmd)->name, "export", 6) == 0)
			(*cmd)->valid_path = ft_strdup("export");
		else if (ft_strncmp((*cmd)->name, "unset", 5) == 0)
			(*cmd)->valid_path = ft_strdup("unset");
		else
			(*cmd)->valid_path = assign_path(input->cmd_exec_tab[(*cmd)->index][0], input, *cmd);
		*cmd = (*cmd)->next;
	}
	*cmd = start;
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
		ft_free((void *)&buff);
	}
	ft_free((void *)&paths_line);
}

char	*assign_path(char *arg, t_input *input, t_cmd_lst *cmd)
{
	int		i;
	char	*path;

	path = NULL;
	i = -1;
	while (input->paths_tab[++i])
	{
		if (access(arg, F_OK) == 0)
		{
			path = ft_strdup(arg);
			return (path);
		}
		path = ft_strjoin(input->paths_tab[i], cmd->name);
		if (access(path, F_OK) == 0)
			return (path);
		ft_free((void *)&path);
	}
	if (access(path, F_OK) == -1 && cmd->index != input->n_cmd - 1)
	{
		ft_putstr_fd(cmd->name, 1);
		ft_putstr_fd(": command not found\n", 1);
		return (NULL);
	}
	if (access(path, F_OK) == -1 && cmd->index == input->n_cmd - 1)
	{
		ft_putstr_fd(cmd->name, 1);
		ft_putstr_fd(": command not found\n", 1);
		exit (127);
	}
	return (NULL);
}
