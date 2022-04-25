/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:41:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/25 17:34:40 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	check_infiles(t_cmd_lst *cmd);

int	cmd_is_built_in(char *name)
{
	if (!name)
		return (0);
	else if (!ft_strncmp(name, "cd", 2) && !name[2])
		return (YES);
	else if (!ft_strncmp(name, "echo", 4) && !name[4])
		return (YES);
	else if (!ft_strncmp(name, "pwd", 3) && !name[3])
		return (YES);
	else if (!ft_strncmp(name, "env", 3) && !name[3])
		return (YES);
	else if (!ft_strncmp(name, "exit", 4) && !name[4])
		return (YES);
	else if (!ft_strncmp(name, "export", 6) && !name[6])
		return (YES);
	else if (!ft_strncmp(name, "unset", 5) && !name[5])
		return (YES);
	else
		return (NO);
}

int	exec_built_in(t_input *input, t_cmd_lst *cmd)
{
	if (check_infiles(cmd) == FAILED)
	{
		g_status = 1;
		return (g_status);
	}
	if (!ft_strncmp(cmd->name, "cd", 2) && !cmd->name[2])
		return (ft_cd(input, cmd));
	else if (!ft_strncmp(cmd->name, "echo", 4) && !cmd->name[4])
		return (ft_echo(input, cmd));
	else if (!ft_strncmp(cmd->name, "pwd", 3) && !cmd->name[3])
		return (ft_pwd());
	else if (!ft_strncmp(cmd->name, "env", 3) && !cmd->name[3])
		return (ft_env(input, cmd));
	else if (!ft_strncmp(cmd->name, "exit", 4) && !cmd->name[4])
		return (ft_exit(input, cmd));
	else if (!ft_strncmp(cmd->name, "export", 6) && !cmd->name[6])
		return (ft_export(input, cmd));
	else if (!ft_strncmp(cmd->name, "unset", 5) && !cmd->name[5])
		return (ft_unset(input, cmd));
	else
		return (FAILED);
}

static int	check_infiles(t_cmd_lst *cmd)
{
	int	i;

	i = -1;
	while (++i < cmd->n_infile)
	{
		if (access(cmd->infile[i], F_OK) != SUCCESS)
			return (FAILED);
	}
	return (SUCCESS);
}
