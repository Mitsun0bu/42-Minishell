/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:19:07 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/24 10:16:40 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	clean_cmd(t_input *input)
{
	int	i;
	int	num;

	input->cmd_exec_tab = ft_calloc(input, sizeof(char **), input->n_cmd + 1);
	input->garbage->type = INPUT_STRUCT;
	num = 0;
	i = -1;
	while (++i < input->n_cmd)
	{
		num = get_arg_num(input->cmd_tab[i]) + 1;
		input->cmd_exec_tab[i] = ft_calloc(input, sizeof(char *), num);
		input->garbage->type = INPUT_STRUCT;
		if (!create_arg_tab(input, i))
			return (0);
	}
	return (1);
}
