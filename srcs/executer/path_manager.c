/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:58:04 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/06 15:19:47 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	path_manager(t_input *input, t_cmd_lst *cmd)
{
	t_cmd_lst	*start;

	start = cmd;
	while (cmd)
	{
		if (!cmd->name)
			cmd->valid_path = NULL;
		else if (find_built_in(cmd->name) == BUILT_IN)
		{
			cmd->valid_path = ft_strdup(input, "built-in");
			input->garbage->type = CMD_LST;
		}
		else if (get_paths_tab(input))
		{
			cmd->valid_path = assign_path(input, cmd, cmd->name);
			input->garbage->type = CMD_LST;
		}
		cmd = cmd->next;
	}
	cmd = start;
}

int	get_paths_tab(t_input *input)
{
	int		i;
	char	*paths_line;

	i = -1;
	paths_line = NULL;
	while (++i < input->n_env)
	{
		if (!ft_strncmp(input->env_tab[i].key, "PATH", 4) && ft_strlen(input->env_tab[i].key) == 4)
		{
			paths_line = ft_strdup(input, input->env_tab[i].value);
			input->garbage->type = GARBAGE;
			break ;
		}
	}
	if (!paths_line)
		return (0);
	input->paths_tab = ft_split(input, paths_line, ':');
	assign_garbage_type(input, input->paths_tab, GARBAGE);
	i = -1;
	while (input->paths_tab[++i])
	{
		input->paths_tab[i] = ft_strjoin(input, input->paths_tab[i], "/");
		input->garbage->type = CMD_LST;
	}
	return (1);
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
		if (access(path, F_OK) == 0)
			return (path);
		input->garbage->type = GARBAGE;
	}
	if (access(path, F_OK) == -1 && cmd->index != input->n_cmd - 1)
		stderror_return(0, "minishelled", cmd->name, "command not found");
	if (access(path, F_OK) == -1 && cmd->index == input->n_cmd - 1)
		stderror_return(127, "minishelled", cmd->name, "command not found");
	return (NULL);
}
