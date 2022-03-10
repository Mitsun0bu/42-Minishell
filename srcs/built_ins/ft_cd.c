/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:56:25 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/10 17:06:52 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_cd(t_input *input, t_cmd_lst *lst_node)
{
	char	*pwd;
	char	*error;

	error = ft_strjoin("cd: ", lst_node->cmd_args[1]);
	if (!lst_node->cmd_args[1])
	{
		update_oldpwd(input);
		chdir(get_value("HOME", input));

	}
	if (lst_node->cmd_index == 0 && access(lst_node->cmd_args[1], F_OK) == 0)
	{
		update_oldpwd(input);
		chdir(lst_node->cmd_args[1]);
	}
	else if (lst_node->cmd_args[1] && access(lst_node->cmd_args[1], F_OK) != 0)
	{
		perror(error);
		ft_free(error);
		return (1);
	}
	pwd = getcwd(NULL, 0);
	change_value(input, "PWD", pwd);
	ft_free(error);
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