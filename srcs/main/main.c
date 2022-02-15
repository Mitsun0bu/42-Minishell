/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:07:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/15 19:12:35 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char **av, char **envp)
{
	t_input	input;
	// t_cmd	*cmd_tab;

	(void)av;
	if (ac > 1)
	{
		printf("To start our shell, use : ./minishell !\n");
		return (1);
	}
	init_shell();
	get_history(&input);
	ft_memset(&input, 0, sizeof(input));
	// ft_memset(&cmd, 0, sizeof(cmd));
	// cmd_tab = malloc((sizeof(t_cmd) + 1) * input.n_cmd);
	// if (!cmd_tab)
	// {
	// 	free(&input);
	// 	return (0);
	// }
	while (1)
	{
		cmd_line_handler(&input);
		lexer(&input);
		parser(&input);
		executer(&input, av, envp);
	// 	ft_free_struct(&input);
	}
	free_struct(&input);
	return (0);
}
