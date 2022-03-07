/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:56:25 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/07 17:25:01 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_cd(t_input *input, t_cmd_lst *lst_node)
{
	char	*value;

	value = ft_strdup(get_value("PWD", input));
	if (!lst_node->cmd_args[1])
		chdir(/*chemin de la racine */);
	if (lst_node->cmd_index == 0 && access(lst_node->cmd_args[1], F_OK) == 0)
	{
		chdir(lst_node->cmd_args[1]);
		change_value(input, "PWD", value);
	}
	else if (access(lst_node->cmd_args[1], F_OK) != 0)
	{
		printf("chdir: no such file or directory: %s\n", lst_node->cmd_args[1]);
		return (1);
	}
	return (0);
}