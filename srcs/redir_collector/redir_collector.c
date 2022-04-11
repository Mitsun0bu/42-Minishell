/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_collector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:36:30 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/11 16:43:43 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	redir_collector(t_input *input)
{
	int	i_cmd;
	int	type;
	int	i_file;

	get_last_redir_type_tab(input);
	malloc_cmd_dimension(input);
	malloc_types_dimension_for_each_cmd(input);
	i_cmd = -1;
	while (++i_cmd < input->n_cmd)
	{
		type = -1;
		while (++type < 4)
			malloc_n_file_dimension_for_each_type(input, i_cmd, type);
		type = -1;
		while (++type < 4)
		{
			i_file = -1;
			while (++i_file < count_n_file(input->cmd_tab[i_cmd], type))
			{
				malloc_name_for_each_file(input, i_cmd, type, i_file);
				copy_name_for_each_file(input, i_cmd, type, i_file);
			}
		}
	}
// ---------------- FINAL TEST ---------------- //
// printf("===================== REDIR_COLLECTOR ======================\n");
// printf("|\t\t~~~~~ REDIR TAB ~~~~~\n");
// int	i = -1;
// while(input->redir_tab[++i])
// {
// 	printf("| COMMAND #%d\n", i);
// 	int j = -1;
// 	while (input->redir_tab[i][++j])
// 	{
// 		printf("|\t-------------------------------------\n");
// 		printf("|\tREDIRECTION TYPE : %d\n", j);
// 		int	k = -1;
// 		while(input->redir_tab[i][j][++k])
// 		{
// 			printf("|\t\t-----------------------------\n");
// 			printf("|\t\tREDIRECTION INDEX : %d\n", k);
// 			printf("|\t\t\tREDIRECTION FILE NAME : %s\n",input->redir_tab[i][j][k]);
// 		}
// 	}
// }
// printf("|\n");
// printf("|\t\t~~~~~ LAST_REDIR_TYPE TAB ~~~~~\n");
// i = -1;
// while(input->redir_tab[++i])
// {
// 	printf("| COMMAND #%d\n", i);
// 	printf("| LAST_infile_TYPE : %d\n", input->last_infile_type[i]);
// 	printf("| LAST_outfile_TYPE : %d\n", input->last_outfile_type[i]);
// }
// printf("============================================================\n");
// // -------------------------------------------- //
}
