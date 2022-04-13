/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:35:01 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/13 11:28:54 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	signal_handler_parent(int signal)
{
	if (signal == SIGINT)
	{
		printf("here\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (signal == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		exit(0);
	}
}

void	signal_handler_child(int signal)
{
	if (signal == SIGINT)
		exit(0);
	if (signal == SIGQUIT)
		exit(0);
}
