/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:56:25 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/16 17:39:04 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_cd(t_input *input, t_cmd_lst *cmd)
{
	char	*pwd;
	char	*error;

	error = ft_strjoin("cd: ", cmd->args[1]);
	if (!cmd->args[1])
	{
		update_oldpwd(input);
		chdir(get_value("HOME", input));

	}
	if (cmd->index == 0 && access(cmd->args[1], F_OK) == 0)
	{
		update_oldpwd(input);
		chdir(cmd->args[1]);
	}
	else if (cmd->args[1] && access(cmd->args[1], F_OK) != 0)
	{
		perror(error);
		ft_free((void *)&error);
		return (1);
	}
	pwd = getcwd(NULL, 0);
	change_value(input, "PWD", pwd);
	ft_free((void *)&error);
	return (0);
}

void	update_oldpwd(t_input *input)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!get_value("OLDPWD", input))
	{
		add_to_env(input, "OLDPWD", 1);
		change_value(input, "OLDPWD", pwd);
	}
	else
		change_value(input, "OLDPWD", pwd);
}