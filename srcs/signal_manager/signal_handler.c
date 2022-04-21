/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:35:01 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/21 17:47:34 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	signal_handler_main(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (signal == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	signal_handler_exec(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
	}
	if (signal == SIGQUIT)
	{
		printf("^\\Quit: 3\n");
	}
}

void	signal_handler_heredoc(int signal)
{
	if (signal == SIGINT)
	{
		// rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		exit(0);
	}
	if (signal == SIGQUIT)
	{
		// essayer de trouver la bonne chose a faire ici
		rl_replace_line("", 0);
		exit(0);
	}
}
