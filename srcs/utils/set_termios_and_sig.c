/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_termios_and_sig.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:45:07 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/22 10:47:56 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	set_termios_and_sig(t_input *input, int mode)
{
	// start exec
	tcsetattr(STDIN_FILENO, TCSANOW, &input->old_term);
	signal(SIGINT, signal_handler_exec);
	signal(SIGQUIT, signal_handler_exec);

	// shell init
	tcgetattr(STDIN_FILENO, &input->old_term);
	signal(SIGINT, signal_handler_main);
	signal(SIGQUIT, signal_handler_main);

	// end exec
	tcsetattr(STDIN_FILENO, TCSANOW, &input->new_term);
	signal(SIGINT, signal_handler_main);
	signal(SIGQUIT, signal_handler_main);

}