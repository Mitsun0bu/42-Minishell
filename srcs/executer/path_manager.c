/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:58:04 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/14 14:27:10 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	path_manager(t_input *input, t_cmd_lst *cmd)
{
	t_cmd_lst	*start;

	start = cmd;
	while (cmd)
	{
		if (cmd->name)
		{
			if (get_valid_path(input, cmd) == FAILED)
			{
				print_error(cmd->name, NULL, "No such file or directory");
				return (FAILED);
			}
		}
		else
			cmd->valid_path = NULL;
		cmd = cmd->next;
	}
	cmd = start;
	return (SUCCESS);
}

int	get_valid_path(t_input *input, t_cmd_lst *cmd)
{
	if (is_built_in(cmd->name) == YES)
	{
		cmd->valid_path = ft_strdup(input, "built-in");
		input->gb->type = CMD_LST;
		return (SUCCESS);
	}
	else if (get_paths_tab(input) == SUCCESS)
	{
		cmd->valid_path = assign_path(input, cmd, cmd->name);
		input->gb->type = CMD_LST;
		if (cmd->valid_path)
		{
			if (access(cmd->valid_path, F_OK) == -1 && cmd->i != input->n_cmd - 1)
			{
				print_error("minishelled", cmd->name, "command not found");
				return (0);
			}
			if (access(cmd->valid_path, F_OK) == -1 && cmd->i == input->n_cmd - 1)
			{
				print_error("minishelled", cmd->name, "command not found");
				return (127);
			}
		}
		return (SUCCESS);
	}
	else
		return (FAILED);
}

int	get_paths_tab(t_input *input)
{
	int		i;
	char	*paths_line;

	i = -1;
	paths_line = NULL;
	paths_line = get_value_from_key(input, "PATH");
	if (!paths_line)
		return (FAILED);
	// Message d'erreur ?
	input->paths_tab = ft_split(input, paths_line, ':');
	assign_gb_type(input, input->paths_tab, GARBAGE);
	i = -1;
	while (input->paths_tab[++i])
	{
		input->paths_tab[i] = ft_strjoin(input, input->paths_tab[i], "/");
		input->gb->type = CMD_LST;
	}
	return (SUCCESS);
}

char	*assign_path(t_input *input, t_cmd_lst *cmd, char *arg)
{
	int		i;
	char	*path;

	path = NULL;
	i = -1;
	while (input->paths_tab[++i])
	{
		if (access(arg, F_OK) == SUCCESS)
		{
			if (opendir(arg) != NULL)
			{
				print_error(NULL, arg, "is a directory");
				return (NULL);
			}
			path = ft_strdup(input, arg);
			return (path);
		}
		path = ft_strjoin(input, input->paths_tab[i], cmd->name);
		if (access(path, F_OK) == SUCCESS)
			return (path);
		input->gb->type = GARBAGE;
	}
	return (NULL);
}
