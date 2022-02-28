/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:07:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/28 09:55:58 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char **av, char **envp)
{
	t_input		input;
	t_cmd_lst	*lst_node;

	(void)av;
	if (ac > 1)
	{
		printf("To start our shell, use : ./minishell !\n");
		return (1);
	}
	ft_memset(&input, 0, sizeof(input));
	ft_memset(&lst_node, 0, sizeof(lst_node));
	init_shell();
	init_env(&input, envp);
	get_history(&input);
	// while (1)
	// {
		cmd_line_manager(&input);
		lexer(&input);
		parser(&input);
		cmd_lst_init(&input, &lst_node);
		executer(envp, &input, &lst_node);
		free_lst(&input, &lst_node);
		free_struct(&input);
	// }
	free_env(&input);
	return (0);
}
