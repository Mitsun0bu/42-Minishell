/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:07:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/11 15:39:35 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char **av, char **envp)
{
	t_input			input;
	t_cmd_lst		*cmd;

	cmd = NULL;
	if (ac > 1 || av[1])
		return (stderror_return(127, "minishelled", av[1], "invalid option"));
	signal(SIGINT, signal_handler_parent);
	signal(SIGQUIT, signal_handler_parent);
	shell_init(envp, &input);
	while (1)
	{
		cmd_line_manager(&input);
		if (cmd_separator(&input) == SUCCESS)
		{
			redir_collector(&input);
			parser(&input);
			cmd_lst_init(&input, &cmd);
			executer(&input, cmd);
			clear_one_garbage_type(&input.garbage, CMD_LST);
			clear_one_garbage_type(&input.garbage, CMD_LINE);
			clear_one_garbage_type(&input.garbage, CMD_TAB);
		}
		clear_one_garbage_type(&input.garbage, INPUT_STRUCT);
		clear_one_garbage_type(&input.garbage, GARBAGE);
	}
}
