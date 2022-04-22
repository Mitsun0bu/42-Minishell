/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:35:01 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/22 17:20:15 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	set_signals(int mode)
{
	if (mode == UNSET)
		signal(SIGINT, SIG_IGN);
	if (mode == MAIN)
	{
		signal(SIGINT, signal_handler_main);
		signal(SIGQUIT, signal_handler_main);
	}
	else if (mode == EXEC)
	{
		signal(SIGINT, signal_handler_exec);
		signal(SIGQUIT, signal_handler_exec);
	}
	else if (mode == HEREDOC)
		signal(SIGINT, signal_handler_heredoc);
	return ;
}

void	signal_handler_main(int signal)
{
	if (signal == SIGINT)
	{
		// working in LVL 1 minishell
		ft_putstr_fd("\n", 2);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (signal == SIGQUIT)
	{
		// working in LVL 1 minishell
		rl_on_new_line();
		rl_redisplay();
	}
}

void	signal_handler_exec(int signal)
{
	if (signal == SIGINT)
	{
		printf("here\n");
		g_status = 130;
	}
	if (signal == SIGQUIT)
	{
		// working in LVL 1 minishell blocking cmd
		ft_putstr_fd("Quit: 3\n", 2);
		g_status = 131;
	}
}

void	signal_handler_parent(int signal)
{
	if (signal == SIGINT)
	{
		// working in LVL 1 minishell blocking cmd
		ft_putstr_fd("\n", 2);
		g_status = 130;
		return ;
	}
	if (signal == SIGQUIT)
	{
		g_status = 131;
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
