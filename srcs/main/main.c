/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:07:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/05 19:26:45 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char **av, char **envp)
{
	t_input			input;
	// t_cmd_lst		*cmd;

	// cmd = NULL;
	if (ac > 1 || av[1])
		return (stderror_return(127, "minishelled", av[1], "invalid option"));
	// signal(SIGINT, signal_handler);
	// signal(SIGQUIT, signal_handler);
	shell_init(envp, &input);

	// TEST MINISPLIT //

	(void)ac;
	(void)av;
	// char *str = "echo \"cat lol.c | cat>lol.c\"";
	char *str = "echo cat lol.c | cat>lol.c";
	char **table = NULL;

	table = ft_mini_split(&input, str, '|');
	printf("table[0] = %s\n", table[0]);
	printf("table[1] = %s\n", table[1]);

	// TEST MINISPLIT //

	// while (1)
	// {
	// 	cmd_line_manager(&input);
	// 	if (cmd_separator(&input) == 1)
	// 	{
	// 		redir_collector(&input);
	// 		parser(&input);
	// 		cmd_lst_init(&input, &cmd);
	// 		executer(&input, cmd);
	// 		clear_one_garbage_type(&input.garbage, CMD_LST);
	// 		clear_one_garbage_type(&input.garbage, CMD_LINE);
	// 		clear_one_garbage_type(&input.garbage, CMD_TAB);
	// 	}
	// 	clear_one_garbage_type(&input.garbage, INPUT_STRUCT);
	// 	clear_one_garbage_type(&input.garbage, GARBAGE);
	// }
	// clear_one_garbage_type(&input.garbage, ENV_STRUCT);
	// clear_all_garbage(&input.garbage);
	// tcsetattr(STDIN_FILENO, TCSANOW, &input.old_term);
	// exit (input.status);
}
