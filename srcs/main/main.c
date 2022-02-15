/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:07:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/15 15:55:59 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char **av)
{
	t_input	input;

	(void)av;
	if (ac > 1)
	{
		printf("To start our shell, use : ./minishell !\n");
		return (1);
	}
	init_shell();
	get_history(&input);
	ft_memset(&input, 0, sizeof(input));
	while (1)
	{
		cmd_line_handler(&input);
		lexer(&input);
		parser(&input);
		// if (input.n_cmd == 1)
		// 	exec_single_cmd(&input);
	// 	ft_free_struct(&input);
	}
	free_struct(&input);
	return (0);
}
