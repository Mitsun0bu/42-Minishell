/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_collector.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:26:57 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/16 10:16:02 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	redir_collector(t_input *input)
{
	int	type;

	fill_last_output_redir_type_tab(input);
	malloc_all_cmd_in_redir_tab(input);
	malloc_redir_types_in_redir_tab(input);
	type = -1;
	while (++type < 4)
	{
		malloc_any_redir_in_redir_tab(input, type);
		malloc_any_filename_in_redir_tab(input, type);
		write_any_redir_in_redir_tab(input, type);
	}
}

	// /* =====	TEST CMD SEPARATOR	===== */
	// int i;
	// i = -1;
	// printf("\n----- TESTEUR DU SEPARATEUR DE COMMANDES -----\n");
	// printf("\n| NOMBRE DE COMMANDES = %d\n", input->n_cmd);
	// while (++i < input->n_cmd)
	// 	printf("| COMMANDE[%d] = %s\n", i, input->cmd_tab[i]);
	// printf("----------------------------------------------\n");
	// /* =====		END OF TEST		===== */

	// /* =====	TEST OUTPUT TYPE	===== */
	// printf("\n----- TESTEUR DU DETECTEUR DE TYPE D'OUTPUT -----\n");
	// int	i;
	// i = -1;
	// while (++i < input->n_cmd)
	// 	printf("| COMMANDE[%d] = %d\n", i, input->last_output_redir_tab[i]);
	// printf("----------------------------------------------\n");
	// /* =====		END OF TEST		===== */

	/* ===== TEST REDIR MANAGER ===== */
	// int	i;
	// i = -1;
	// while (++i)
	// 	printf("%c\n", input->redir_tab[i]);
	/* =====		END OF TEST		===== */

	// // ---------------- FINAL TEST ---------------- //
	// printf("===================== redir_collector =====================\n");
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
	// printf("\n|\t\t~~~~~ REDIR TAB ~~~~~\n");
	// i = -1;
	// while(input->redir_tab[++i])
	// {
	// 	printf("| COMMAND #%d\n", i);
	// 	printf("| LAST_OUTPUT_REDIR_TYPE : %d\n", input->last_output_redir_tab[i]);
	// }
	// printf("=================================================\n");
	// // -------------------------------------------- //