/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:58:04 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/29 11:10:34 by llethuil         ###   ########lyon.fr   */
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
		else if (find_built_in((*cmd)->name) == BUILT_IN)
			(*cmd)->valid_path = ft_strdup(input, "built-in");
		else
			(*cmd)->valid_path = assign_path(input, *cmd,
					input->cmd_exec_tab[(*cmd)->index][0]);
		input->garbage->type = CMD_LST;
		*cmd = (*cmd)->next;
	}
	*cmd = start;
}

void	get_paths_tab(char **envp, t_input	*input)
{
	int		i;
	char	*paths_line;

	i = -1;
	paths_line = NULL;
	while (*envp)
	{
		if (ft_strnstr(*envp, "PATH=", 5) != NULL)
		{
			paths_line = ft_substr(input, *envp, 5, ft_strlen(*envp));
			input->garbage->type = GARBAGE;
			break ;
		}
		envp++;
	}
	input->paths_tab = ft_split(input, paths_line, ':');
	input->garbage->type = GARBAGE;
	while (input->paths_tab[++i])
	{
		input->paths_tab[i] = ft_strjoin(input, input->paths_tab[i], "/");
		input->garbage->type = CMD_LST;
	}
}

char	*assign_path(t_input *input, t_cmd_lst *cmd, char *arg)
{
	int		i;
	char	*path;

	path = NULL;
	i = -1;
	while (input->paths_tab[++i])
	{
		if (access(arg, F_OK) == 0)
		{
			path = ft_strdup(input, arg);
			return (path);
		}
		path = ft_strjoin(input, input->paths_tab[i], cmd->name);
		input->garbage->type = GARBAGE;
		if (access(path, F_OK) == 0)
			return (path);
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
