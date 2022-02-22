/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:07:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/22 18:11:59 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char **av, char **envp)
{
	t_input		input;
	t_cmd_lst	*lst_head;

	(void)av;
	lst_head = NULL;
	if (ac > 1)
	{
		printf("To start our shell, use : ./minishell !\n");
		return (1);
	}
	init_shell();
	get_history(&input);
	ft_memset(&input, 0, sizeof(input));
	ft_memset(&lst_head, 0, sizeof(lst_head));
	while (1)
	{
		cmd_line_handler(&input);
		lexer(&input);
		parser(&input);
		cmd_lst_init(&input, &lst_head);
		executer(av, envp, &input, &lst_head);
		free_lst(&lst_head);
		free_struct(&input);
	}
	return (0);
}
