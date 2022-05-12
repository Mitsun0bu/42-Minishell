/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:22:25 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/12 09:30:48 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_err(int err_no, char *who, char *problem, char *err_mess)
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
	if (err_mess)
	{
		ft_putstr_fd(err_mess, 2);
		ft_putstr_fd("\n", 2);
	}
	g_status = err_no;
}

int	exit_err(t_input *input, int err_no, char *problem, char *err_mess)
{
	ft_putstr_fd("minishelled: ", 2);
	if (problem)
	{
		ft_putstr_fd(problem, 2);
		ft_putstr_fd(": ", 2);
	}
	if (err_mess)
	{
		ft_putstr_fd(err_mess, 2);
		ft_putstr_fd("\n", 2);
	}
	clear_all_gb(&input->gb);
	set_termios(input, UNSET);
	exit(err_no);
}
