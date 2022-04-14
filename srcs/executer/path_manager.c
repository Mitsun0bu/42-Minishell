/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:58:04 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/14 10:59:15 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	path_manager(t_input *input, t_cmd_lst *cmd)
{
	t_cmd_lst	*start;

	start = cmd;
	while (cmd)
	{
		if (cmd->name)
		{
			if (is_built_in(cmd->name) == YES)
			{
				cmd->valid_path = ft_strdup(input, "built-in");
				input->gb->type = CMD_LST;
			}
			else if (get_paths_tab(input) == SUCCESS)
			{
				cmd->valid_path = assign_path(input, cmd, cmd->name);
				input->gb->type = CMD_LST;
			}
		}
		else
			cmd->valid_path = NULL;
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
		if (!ft_strncmp(input->env_tab[i].key, "PATH", 4)
			&& ft_strlen(input->env_tab[i].key) == 4)
		{
			paths_line = ft_strdup(input, input->env_tab[i].value);
			input->gb->type = GARBAGE;
			break ;
		}
	}
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
				return (err_return_char(NULL, NULL, arg, "is a directory"));
			path = ft_strdup(input, arg);
			return (path);
		}
		path = ft_strjoin(input, input->paths_tab[i], cmd->name);
		if (access(path, F_OK) == SUCCESS)
			return (path);
		input->gb->type = GARBAGE;
	}
	if (access(path, F_OK) == -1 && cmd->i != input->n_cmd - 1)
		err_return(0, "minishelled", cmd->name, "command not found");
	if (access(path, F_OK) == -1 && cmd->i == input->n_cmd - 1)
		err_return(127, "minishelled", cmd->name, "command not found");
	return (NULL);
}
