/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:56:25 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/04 18:55:06 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	check_access_error(t_input *input, t_cmd_lst *cmd, char *home);
static void	call_update_oldpwd(t_input *input, t_cmd_lst *cmd, char *home);
static void	update_oldpwd(t_input *input, char *destination);
static void	update_pwd(t_input *input);

int	ft_cd(t_input *input, t_cmd_lst *cmd)
{
	char	*home;

	home = get_value_from_key(input, "HOME");
	if (check_access_error(input, cmd, home) == FAILED)
		return (g_status);
	call_update_oldpwd(input, cmd, home);
	if (find_existing_env_var(input, "PWD") == NO)
		add_to_env_tab(input, "PWD", ENV);
	update_pwd(input);
	return (0);
}

static int	check_access_error(t_input *input, t_cmd_lst *cmd, char *home)
{
	if (!home && !cmd->args[1])
	{
		print_err(1, NULL, "cd", "HOME not set");
		return (FAILED);
	}
	else if (cmd->args[1] && ft_strcmp(cmd->args[1], "-") == SUCCESS)
	{
		if (!get_value_from_key(input, "OLDPWD"))
			print_err(1, NULL, "cd", "OLDPWD not set");
		else if (open(get_value_from_key(input, "OLDPWD"), O_DIRECTORY) == -1)
			print_err(1, "minishelled: cd", get_value_from_key(input, "OLDPWD"),
				"No such file or directory");
		if (!get_value_from_key(input, "OLDPWD")
			|| open(get_value_from_key(input, "OLDPWD"), O_DIRECTORY) == -1)
			return (FAILED);
	}
	else if (cmd->args[1] && open(cmd->args[1], O_DIRECTORY) == -1)
	{
		print_err(1, "minishelled: cd",
			cmd->args[1], "No such file or directory");
		return (FAILED);
	}
	return (SUCCESS);
}

static void	call_update_oldpwd(t_input *input, t_cmd_lst *cmd, char *home)
{
	if (find_existing_env_var(input, "OLDPWD") == NO)
		add_to_env_tab(input, "OLDPWD", ENV);
	if (!cmd->args[1])
		update_oldpwd(input, home);
	else if ((cmd->args[1] && ft_strcmp(cmd->args[1], "-") == SUCCESS))
	{
		printf("%s\n", get_value_from_key(input, "OLDPWD"));
		update_oldpwd(input, get_value_from_key(input, "OLDPWD"));
	}
	else
		update_oldpwd(input, cmd->args[1]);
}

static void	update_oldpwd(t_input *input, char *destination)
{
	update_pwd(input);
	change_value(input, "OLDPWD", input->cwd);
	chdir(destination);
}

static void	update_pwd(t_input *input)
{
	char	*pwd;
	char	*pwd_gb;

	pwd_gb = NULL;
	pwd = getcwd(NULL, 0);
	if (pwd)
	{
		pwd_gb = ft_strdup(input, pwd);
		input->gb->type = ENV_STRUCT;
		ft_free((void *)&pwd);
	}
	if (pwd_gb)
	{
		change_value(input, "PWD", pwd_gb);
		input->cwd = pwd_gb;
	}
}
