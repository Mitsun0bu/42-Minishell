/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:07:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/11 11:59:07 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

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

	while (1)
	{
		ft_memset(&input, 0, sizeof(input));
		main_cmd_line_handler(&input);
		main_lexer(&input);
		main_parser(&input);
		// if (ft_cmd_counter(&input) == 0)
		// 	ft_exec_single_cmd(&input);
	// 	ft_free_struct(&input);
	}
	free_struct(&input);
	return (0);
}
