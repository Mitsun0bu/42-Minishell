/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:07:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/16 15:37:31 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char **av, char **envp)
{
	t_input		input;
	t_cmd_lst	*cmd;

	(void)av;
	shell_init(ac, envp, &input, &cmd);
	while (1)
	{
		cmd_line_manager(&input);
		cmd_separator(&input);
		redir_collector(&input);
		parser(&input);
		cmd_lst_init(&input, &cmd);
		executer(envp, &input, &cmd);
		free_lst(&cmd);
		free_input_struct(&input);
	}
	free_env_struct(&input);
	exit (0);
}
