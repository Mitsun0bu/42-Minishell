/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:07:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/23 17:52:42 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char **av, char **envp)
{
	t_input			input;
	t_cmd_lst		*cmd;

	if (ac > 1 || av[1])
		return (print_stderror(127, av[1], ": invalid option"));
	shell_init(envp, &input, &cmd);
	while (1)
	{
		cmd_line_manager(&input);
		if (cmd_separator(&input) == 1)
		{
			redir_collector(&input);
			parser(&input);
			cmd_lst_init(&input, &cmd);
			executer(envp, &input, &cmd);
			free_lst(&cmd);
		}
		free_input_struct(&input);
	}
	free_env_struct(&input);
	exit (0);
}

int	stderror_print_return(int error, char *problem, char *err_message)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(problem, 2);
	ft_putstr_fd(err_message, 2);
	ft_putstr_fd("\n", 2);
	return (error);
}

int	stderror_print_exit(t_input *input, char *problem, char *err_message)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(problem, 2);
	ft_putstr_fd(err_message, 2);
	ft_putstr_fd("\n", 2);
	exit(-1);
}