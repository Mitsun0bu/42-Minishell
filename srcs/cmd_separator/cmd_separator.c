/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_separator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:29:56 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/14 13:33:06 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	cmd_separator(t_input *input)
{
	if (check_pipe(input) == FAILED)
	{
		printf("minishelled: syntax error near unexpected token `|'\n");
		return (FAILED);
	}
	if (split_cmd(input) == FAILED)
		return (FAILED);
	if (check_quotes_and_redir(input) == FAILED)
		return (FAILED);
	return (SUCCESS);
}

// 	// ---------------- FINAL TEST ---------------- //
// printf("====================== CMD_SEPARATOR =======================");
// int i;
// i = -1;
// printf("\n| NOMBRE DE COMMANDES = %d\n", input->n_cmd);
// while (++i < input->n_cmd)
// 	printf("| COMMANDE[%d] = %s\n", i, input->cmd_tab[i]);
// printf("============================================================\n");
// // ----------------- END OF TEST ---------------//