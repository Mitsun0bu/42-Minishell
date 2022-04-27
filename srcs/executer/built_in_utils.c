/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:41:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/27 17:54:25 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	check_infiles(t_cmd_lst *cmd);

int	cmd_is_built_in(char *name)
{
	if (!name)
		return (0);
	else if (ft_strcmp(name, "cd") == SUCCESS)
		return (YES);
	else if (ft_strcmp(name, "echo") == SUCCESS)
		return (YES);
	else if (ft_strcmp(name, "pwd") == SUCCESS)
		return (YES);
	else if (ft_strcmp(name, "env") == SUCCESS)
		return (YES);
	else if (ft_strcmp(name, "exit") == SUCCESS)
		return (YES);
	else if (ft_strcmp(name, "export") == SUCCESS)
		return (YES);
	else if (ft_strcmp(name, "unset") == SUCCESS)
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
	if (ft_strcmp(cmd->name, "cd")== SUCCESS)
		return (ft_cd(input, cmd));
	else if (ft_strcmp(cmd->name, "echo")== SUCCESS)
		return (ft_echo(input, cmd));
	else if (ft_strcmp(cmd->name, "pwd")== SUCCESS)
		return (ft_pwd());
	else if (ft_strcmp(cmd->name, "env")== SUCCESS)
		return (ft_env(input, cmd));
	else if (ft_strcmp(cmd->name, "exit")== SUCCESS)
		return (ft_exit(input, cmd));
	else if (ft_strcmp(cmd->name, "export")== SUCCESS)
		return (ft_export(input, cmd));
	else if (ft_strcmp(cmd->name, "unset")== SUCCESS)
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
