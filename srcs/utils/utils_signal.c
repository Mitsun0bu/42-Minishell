/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:35:01 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/25 19:30:56 by llethuil         ###   ########lyon.fr   */
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
	{
		signal(SIGINT, signal_handler_heredoc);
		signal(SIGQUIT, signal_handler_heredoc);
	}
	else if (mode == PIPE)
	{
		signal(SIGINT, signal_handler_final_pipe);
		signal(SIGQUIT, signal_handler_final_pipe);
	}
	return ;
}

void	signal_handler_main(int signal)
{
	if (signal == SIGINT)
	{
		ft_putstr_fd("\n", 2);
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
		return ;
	if (signal == SIGQUIT)
		return ;
}

void	signal_handler_heredoc(int signal)
{
	if (signal == SIGINT)
	{
		ft_putstr_fd("\n", 2);
		rl_on_new_line();
		rl_replace_line("", 0);
		exit(0);
	}
	if (signal == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	signal_handler_final_pipe(int signal)
{
	if (signal == SIGINT)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		exit(0);
	}
	if (signal == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}
