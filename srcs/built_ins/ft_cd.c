/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:56:25 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/14 13:44:43 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_cd(t_input *input, t_cmd_lst *cmd)
{
	char	*home;
	char	*pwd;
	char	*pwd_gb;

	home = get_value_from_key(input, "HOME");
	if (!home && !cmd->args[1])
	{
		print_error(NULL, "cd", "HOME not set");
		return (1);
	}
	if (!cmd->args[1])
		update_oldpwd(input, home);
	if (cmd->i == 0 && access(cmd->args[1], F_OK) == 0)
		update_oldpwd(input, cmd->args[1]);
	else if (cmd->args[1] && access(cmd->args[1], F_OK) != 0)
	{
		print_error("minishelled: cd", cmd->args[1], "No such file or directory");
		return (1);
	}
	pwd = getcwd(NULL, 0);
	pwd_gb = ft_strdup(input, pwd);
	input->gb->type = ENV_STRUCT;
	ft_free((void *)&pwd);
	change_value(input, "PWD", pwd_gb);
	return (0);
}

void	update_oldpwd(t_input *input, char *destination)
{
	char	*pwd;
	char	*pwd_gb;

	pwd = getcwd(NULL, 0);
	pwd_gb = ft_strdup(input, pwd);
	input->gb->type = ENV_STRUCT;
	ft_free((void *)&pwd);
	if (!get_value_from_key(input, "OLDPWD"))
	{
		add_to_env(input, "OLDPWD", ENV_NULL);
		change_value(input, "OLDPWD", pwd_gb);
	}
	else
		change_value(input, "OLDPWD", pwd_gb);
	chdir(destination);
}
