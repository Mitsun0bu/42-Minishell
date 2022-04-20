/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:56:25 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/20 09:35:16 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_cd(t_input *input, t_cmd_lst *cmd)
{
	char	*home;
	char	*pwd;
	char	*pwd_gb;

	home = get_value_from_key(input, "HOME");
	if (check_access_error(cmd, home) == FAILED)
		return (1);
	call_update_oldpwd(input, cmd, home);
	pwd = getcwd(NULL, 0);
	pwd_gb = ft_strdup(input, pwd);
	input->gb->type = ENV_STRUCT;
	ft_free((void *)&pwd);
	change_value(input, "PWD", pwd_gb);
	return (0);
}

int	check_access_error(t_cmd_lst *cmd, char *home)
{
	if (!home && !cmd->args[1])
	{
		print_err(1, NULL, "cd", "HOME not set");
		return (FAILED);
	}
	else if (cmd->args[1] && access(cmd->args[1], F_OK) != 0)
	{
		print_err(1, "minishelled: cd",
			cmd->args[1], "No such file or directory");
		return (FAILED);
	}
	else
		return (SUCCESS);
}

void	call_update_oldpwd(t_input *input, t_cmd_lst *cmd, char *home)
{
	if (!cmd->args[1])
		update_oldpwd(input, home);
	else if (cmd->i == 0 && access(cmd->args[1], F_OK) == 0)
		update_oldpwd(input, cmd->args[1]);
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
		add_to_env_tab(input, "OLDPWD", ENV_NULL);
		change_value(input, "OLDPWD", pwd_gb);
	}
	else
		change_value(input, "OLDPWD", pwd_gb);
	chdir(destination);
}
