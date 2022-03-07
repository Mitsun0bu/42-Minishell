/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:45:14 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/07 11:40:19 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	redir_input(t_cmd_lst *lst_node)
{
	int	i;

	i = -1;
	while (++i < lst_node->n_input_redir)
		dup2(lst_node->fd_input[i], STDIN_FILENO);
	return (1);
}

int	redir_output(t_cmd_lst *lst_node)
{
	int	i;

	i = -1;
	while (++i < lst_node->n_output_redir)
		dup2(lst_node->fd_output[i], STDOUT_FILENO);
	return (1);
}

int	redir_app_output(t_cmd_lst *lst_node)
{
	int	i;

	i = -1;
	while (++i < lst_node->n_app_output_redir)
		dup2(lst_node->fd_app_output[i], STDOUT_FILENO);
	return (1);
}
