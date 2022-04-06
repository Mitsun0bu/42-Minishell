/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:56:25 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/06 17:10:33 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_cd(t_input *input, t_cmd_lst *cmd)
{
	char	*pwd;
	char	*home;

	home = get_value(input, "HOME");
	if (!cmd->args[1])
	{
		if (!home)
			stderror_return(1, NULL, "cd", "HOME not set");
		update_oldpwd(input);
		chdir(home);
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
		add_to_env(input, "OLDPWD", ENV_NULL);
		change_value(input, "OLDPWD", pwd);
	}
	else
		change_value(input, "OLDPWD", pwd);
}
