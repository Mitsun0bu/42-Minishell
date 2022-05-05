/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:11:09 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/05 09:34:11 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	get_paths_tab_from_env_tab(t_input *input);
static int	cmd_name_is_a_valid_relative_path(t_cmd_lst *cmd);
static char	*assign_path_to_cmd(t_input *input, char *cmd_name);

int	get_path(t_input *input, t_cmd_lst *cmd)
{
	if (get_paths_tab_from_env_tab(input) == FAILED)
	{
		print_err(127, cmd->name, NULL, "No such file or directory");
		return (FAILED);
	}
	if (ft_strchr(cmd->name, '/') != NULL)
	{
		if (cmd_name_is_a_valid_relative_path(cmd) == YES)
			return (SUCCESS);
		g_status = 127;
		return (FAILED);
	}
	cmd->valid_path = assign_path_to_cmd(input, cmd->name);
	input->gb->type = CMD_LST;
	if (ft_strcmp(cmd->name, "export") == SUCCESS
		|| ft_strcmp(cmd->name, "unset") == SUCCESS)
		return (SUCCESS);
	if (!cmd->valid_path)
	{
		print_err(127, "minishelled", cmd->name, "command not found");
		return (FAILED);
	}
	return (SUCCESS);
}

static int	get_paths_tab_from_env_tab(t_input *input)
{
	int		i;
	char	*paths_line;

	i = -1;
	paths_line = NULL;
	paths_line = get_value_from_key(input, "PATH");
	if (!paths_line)
		return (FAILED);
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

static int	cmd_name_is_a_valid_relative_path(t_cmd_lst *cmd)
{
	if (access(cmd->name, F_OK) == SUCCESS && opendir(cmd->name) == NULL)
	{
		cmd->valid_path = cmd->name;
		return (YES);
	}
	else
	{
		print_err(127, NULL, cmd->name, "No such file or directory");
		return (NO);
	}
}

static char	*assign_path_to_cmd(t_input *input, char *cmd_name)
{
	int		i;
	char	*path;

	path = NULL;
	i = -1;
	while (input->paths_tab[++i])
	{
		path = ft_strjoin(input, input->paths_tab[i], cmd_name);
		if (access(path, F_OK) == SUCCESS)
			return (path);
		input->gb->type = GARBAGE;
	}
	return (NULL);
}
