/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_set_termios.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:45:07 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/22 14:52:31 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	set_termios(t_input *input, int mode)
{
	if (mode == YES)
	{
		tcgetattr(STDIN_FILENO, &input->default_term);
		input->minishelled_term = input->default_term;
		input->minishelled_term.c_lflag &= ~(ICANON | ECHOCTL);
		tcsetattr(STDIN_FILENO, TCSANOW, &input->minishelled_term);
	}
	else if (mode == UNSET)
	{
		tcgetattr(STDIN_FILENO, &input->minishelled_term);
		input->default_term = input->minishelled_term;
		input->default_term.c_lflag |= (ICANON | ECHOCTL);
		tcsetattr(STDIN_FILENO, TCSANOW, &input->default_term);
	}
}

