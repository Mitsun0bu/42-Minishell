/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:26:57 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/03 10:39:13 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "main.h"

void	lexer(t_input *input)
{
	if (!ft_strchr(input->cmd_line, '|'))
		single_cmd(input);
	else
		split_multi_cmd(input);
	fill_last_output_redir_type_tab(input);
	printf("\n----- TESTEUR DU DETECTEUR DE TYPE D'OUTPUT -----\n");
	int i;
	i = -1;
	while (++i < input->n_cmd)
		printf("| COMMANDE[%d] = %d\n", i, input->last_output_redir_tab[i]);
	printf("----------------------------------------------\n");
	malloc_redir_tab(input);
	malloc_redir_subdiv(input);
	malloc_input_redir_tab(input);
	malloc_output_redir_tab(input);
	malloc_heredoc_redir_tab(input);
	malloc_app_output_redir_tab(input);
	malloc_redir_solo(input);
	fill_redir_tab_input(input);
	fill_redir_tab_output(input);
	fill_redir_tab_heredoc(input);
	fill_redir_tab_app_output(input);
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

	// ---------------- FINAL TEST ---------------- //
	// int	i = -1;
	// while(input->redir_tab[++i])
	// {
	// 	printf("=============================================\n");
	// 	printf("command : %d\n", i);
	// 	int j = -1;
	// 	while (input->redir_tab[i][++j])
	// 	{
	// 		printf("\t-------------------------------------\n");
	// 		printf("\tredirection type : %d\n", j);
	// 		int	k = -1;
	// 		while(input->redir_tab[i][j][++k])
	// 		{
	// 			printf("\t\t-----------------------------\n");
	// 			printf("\t\tredirection index : %d\n", k);
	// 			printf("\t\t\tred = %s\n",input->redir_tab[i][j][k]);
	// 		}
	// 	}
	// }
	// -------------------------------------------- //

	/* ===== TEST REDIR MANAGER ===== */
	// int	i;
	// i = -1;
	// while (++i)
	// 	printf("%c\n", input->redir_tab[i]);
	/* =====		END OF TEST		===== */