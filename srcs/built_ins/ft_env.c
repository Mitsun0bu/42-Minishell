/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:15:24 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/25 17:33:46 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_env(t_input *input, t_cmd_lst *cmd)
{
	int	i;

	if (cmd->args[1])
	{
		print_err(127, "env", cmd->args[1], "No such file or directory");
		return (127);
	}
	i = -1;
	while (++i < input->n_env)
	{
		if (input->env_tab[i].type == ENV)
		{
			printf("%s=", input->env_tab[i].key);
			printf("%s\n", input->env_tab[i].value);
		}
		else if (input->env_tab[i].type == ENV_EMPTY)
			printf("%s=\n", input->env_tab[i].key);
	}
	return (0);
}
