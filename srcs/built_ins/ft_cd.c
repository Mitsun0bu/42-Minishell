/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:56:25 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/24 15:23:08 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_cd(t_input *input, t_cmd_lst *cmd)
{
	char	*pwd;

	if (!cmd->args[1])
	{
		update_oldpwd(input);
		chdir(get_value(input, "HOME"));
	}
	if (cmd->index == 0 && access(cmd->args[1], F_OK) == 0)
	{
		update_oldpwd(input);
		chdir(cmd->args[1]);
	}
	else if (cmd->args[1] && access(cmd->args[1], F_OK) != 0)
		return (1);
	pwd = getcwd(NULL, 0);
	change_value(input, "PWD", pwd);
	return (0);
}

void	update_oldpwd(t_input *input)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!get_value(input, "OLDPWD"))
	{
		add_to_env(input, "OLDPWD", 1);
		change_value(input, "OLDPWD", pwd);
	}
	else
		change_value(input, "OLDPWD", pwd);
}