/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:35:01 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/07 12:03:42 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	signal_handler_parent(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	if (signal == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	signal_handler_child(int signal)
{
	if (signal == SIGINT)
	{
		rl_replace_line("", 0);
		rl_replace_line("", 0);
		rl_on_new_line();
		exit(0);
	}
	if (signal == SIGQUIT)
	{
		exit(0);
	}
}