/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:07:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/12 15:47:37 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char **av, char **envp)
{
	t_input		input;
	t_cmd_lst	*cmd;

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
			clear_one_gb_type(&input.gb, CMD_LST);
			clear_one_gb_type(&input.gb, CMD_LINE);
			clear_one_gb_type(&input.gb, CMD_TAB);
		}
		clear_one_gb_type(&input.gb, INPUT_STRUCT);
		clear_one_gb_type(&input.gb, GARBAGE);
	}
	// clear_one_gb_type(&input.gb, ENV_STRUCT);
	// ft_clear_all_gb(&input.gb);
	// exit (0);
}
