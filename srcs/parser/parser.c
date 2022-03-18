/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:23:14 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/18 15:22:25 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	parser(t_input *input)
{

	if (!clean_command(input))
	{
		free_triple(input->cmd_exec_tab);
		return (0);
	}
	return (1);
}

// ---------------- DEBUG ---------------- //
// int i = -1;
// int j;
// while (input->cmd_exec_tab[++i])
// {
// 	j = -1;
// 	printf("\n- - - - - - - - PARSER - - - - - - - -\n");
// 	printf("| TEST with : %s\n", input->cmd_tab[i]);
// 	printf("| ARG NUM : %d\n", get_arg_num(input->cmd_tab[i]));
// 	while (input->cmd_exec_tab[i][++j])
// 		printf("| CMD_EXEC_TAB[%d][%d] %s\n",i, j, input->cmd_exec_tab[i][j]);
// 	printf("- - - - - - - - - - - - - - - - - - - - -\n");
// }
// -------------------------------------- //