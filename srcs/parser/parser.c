/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:23:14 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/14 12:08:13 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parser.h"
#include "../../incs/utils.h"

int	parser(t_input *input)
{
	if (!check_basics(input))
		return (0);
	if (!clean_command(input))
	{
		free_triple(input->cmd_exec_tab);
		return (0);
	}
	// // ---------------- DEBUG ---------------- //

	int i = -1;
	int j;

	while (input->cmd_exec_tab[++i])
	{
		j = -1;
		printf("%s\n\n", input->cmd_tab[i]);
		printf("\nARG NUM : %d\n", get_arg_num(input->cmd_tab[i]));
		while (input->cmd_exec_tab[i][++j])
		{
			printf("[%d] %s\n", j, input->cmd_exec_tab[i][j]);
		}
		printf("\n\n-------------------------------\n\n");
	}

	// // -------------------------------------- //
	return (1);
}
