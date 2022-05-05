/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:11:09 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/05 11:51:22 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	get_paths_tab_from_env_tab(t_input *input);
static int	handle_path_exceptions(t_cmd_lst *cmd);
static int	cmd_name_is_a_valid_relative_path(t_cmd_lst *cmd);
static char	*assign_path_to_cmd(t_input *input, char *cmd_name);

int	get_path(t_input *input, t_cmd_lst *cmd)
{
	int	result;

	if (get_paths_tab_from_env_tab(input) == FAILED)
	{
		print_err(127, cmd->name, NULL, "No such file or directory");
		return (FAILED);
	}
	result = handle_path_exceptions(cmd);
	if (result == FAILED)
		return (FAILED);
	else if (result == YES)
		return (SUCCESS);
	else
	{
		cmd->valid_path = assign_path_to_cmd(input, cmd->name);
		input->gb->type = CMD_LST;
		if (!cmd->valid_path)
		{
			print_err(127, "minishelled", cmd->name, "command not found");
			return (FAILED);
		}
		return (SUCCESS);
	}
}

static int	handle_path_exceptions(t_cmd_lst *cmd)
{
	if (ft_strchr(cmd->name, '/') != NULL)
	{
		if (cmd_name_is_a_valid_relative_path(cmd) == YES)
			return (YES);
		g_status = 127;
		return (FAILED);
	}
	if (ft_strcmp(cmd->name, "export") == SUCCESS
		|| ft_strcmp(cmd->name, "unset") == SUCCESS)
		return (SUCCESS);
	if (ft_strcmp(cmd->name, ".") == SUCCESS
		|| ft_strcmp(cmd->name, "..") == SUCCESS)
	{
		print_err(127, "minishelled", cmd->name, "command not found");
		return (FAILED);
	}
	return (NO);
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
		 if (access(cmd->name, X_OK))
		{
			print_err(126, NULL, cmd->name, "Permission denied");
			return (NO);
		}
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
