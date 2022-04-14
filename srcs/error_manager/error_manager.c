/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:22:25 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/14 13:50:10 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// int	err_return(int error, char *who, char *problem, char *err_message)
// {
// 	if (!who)
// 	{
// 		ft_putstr_fd("minishelled: ", 2);
// 		ft_putstr_fd(problem, 2);
// 	}
// 	if (who)
// 	{
// 		ft_putstr_fd(who, 2);
// 		ft_putstr_fd(": ", 2);
// 		ft_putstr_fd(problem, 2);
// 	}
// 	if (err_message)
// 	{
// 		ft_putstr_fd(": ", 2);
// 		ft_putstr_fd(err_message, 2);
// 		ft_putstr_fd("\n", 2);
// 	}
// 	return (error);
// }

void	print_error(char *who, char *problem, char *err_message)
{
	if (!who)
	{
		ft_putstr_fd("minishelled: ", 2);
		ft_putstr_fd(problem, 2);
	}
	if (who)
	{
		ft_putstr_fd(who, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(problem, 2);
	}
	if (err_message)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(err_message, 2);
		ft_putstr_fd("\n", 2);
	}
}

// char *err_return_char(char *error, char *who, char *problem, char *err_message)
// {
// 	if (!who)
// 	{
// 		ft_putstr_fd("minishelled: ", 2);
// 		ft_putstr_fd(problem, 2);
// 		ft_putstr_fd(": ", 2);
// 	}
// 	if (who)
// 	{
// 		ft_putstr_fd(who, 2);
// 		ft_putstr_fd(": ", 2);
// 		ft_putstr_fd(problem, 2);
// 	}
// 	if (err_message)
// 	{
// 		ft_putstr_fd(": ", 2);
// 		ft_putstr_fd(err_message, 2);
// 		ft_putstr_fd("\n", 2);
// 	}
// 	return (error);
// }

int	err_exit(t_input *input, int error, char *problem, char *err_message)
{
	if (problem)
	{
		ft_putstr_fd("minishelled: ", 2);
		ft_putstr_fd(problem, 2);
		ft_putstr_fd(": ", 2);
	}
	if (err_message)
	{
		ft_putstr_fd(err_message, 2);
		ft_putstr_fd("\n", 2);
	}
	clear_all_gb(&input->gb);
	tcsetattr(STDIN_FILENO, TCSANOW, &input->old_term);
	exit(error);
}
