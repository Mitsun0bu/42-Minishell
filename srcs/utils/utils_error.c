/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:22:25 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/22 14:43:58 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_err(int err_no, char *who, char *problem, char *err_message)
{
	if (!who)
		ft_putstr_fd("minishelled: ", 2);
	if (who)
	{
		ft_putstr_fd(who, 2);
		ft_putstr_fd(": ", 2);
	}
	if (problem)
	{
		ft_putstr_fd(problem, 2);
		ft_putstr_fd(": ", 2);
	}
	if (err_message)
	{
		ft_putstr_fd(err_message, 2);
		ft_putstr_fd("\n", 2);
	}
	g_status = err_no;
}

int	exit_err(t_input *input, int error, char *problem, char *err_message)
{
	ft_putstr_fd("minishelled: ", 2);
	if (problem)
	{
		ft_putstr_fd(problem, 2);
		ft_putstr_fd(": ", 2);
	}
	if (err_message)
	{
		ft_putstr_fd(err_message, 2);
		ft_putstr_fd("\n", 2);
	}
	clear_all_gb(&input->gb);
	// get_and_set_termios(input, "new", "old");
	set_termios(input, UNSET);
	exit(error);
}
