/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:19:07 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/10 11:23:30 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parser.h"

int	clean_command(t_input *input)
{
	int	i;

	input->cmd_exec_tab = ft_calloc(input->n_cmd + 1, sizeof(char **));
	if (!input->cmd_exec_tab)
		return (0);
	i = -1;
	while (++i < input->n_cmd)
	{
		input->cmd_exec_tab[i] = ft_calloc(get_arg_num(input->cmd_tab[i])
				+ 1, sizeof(char *));
		if (!input->cmd_exec_tab[i])
			return (0);
		if (!create_arg_tab(input, i))
			return (0);
	}
	return (1);
}
