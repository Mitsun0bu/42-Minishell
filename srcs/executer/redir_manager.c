/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:45:14 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/10 14:48:26 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	handle_input_redir(t_cmd_lst *lst_node)
{
	int	redir_in;

	redir_in = 0;
	if (lst_node->n_input_redir)
		redir_in = dup_redir_input(lst_node);
	return(redir_in);
}

int	handle_output_redir(t_input *input, t_cmd_lst *lst_node)
{
	int	redir_out;

	redir_out = 0;
	if (input->last_output_redir_tab[lst_node->cmd_index] == TRUNC_OUTPUT)
	{
		if (lst_node->n_app_output_redir)
			redir_out = dup_redir_app_output(lst_node);
		redir_out = dup_redir_output(lst_node);
	}
	else if (input->last_output_redir_tab[lst_node->cmd_index] == APP_OUTPUT)
	{
		if (lst_node->n_app_output_redir)
			redir_out = dup_redir_output(lst_node);
		redir_out = dup_redir_app_output(lst_node);
	}
	return (redir_out);
}

int	dup_redir_input(t_cmd_lst *lst_node)
{
	int	i;

	i = -1;
	while (++i < lst_node->n_input_redir)
			dup2(lst_node->fd_input[i], STDIN_FILENO);
	return (1);
}

int	dup_redir_output(t_cmd_lst *lst_node)
{
	int	i;

	i = -1;
	while (++i < lst_node->n_output_redir)
		dup2(lst_node->fd_output[i], STDOUT_FILENO);
	return (1);
}

int	dup_redir_app_output(t_cmd_lst *lst_node)
{
	int	i;

	i = -1;
	while (++i < lst_node->n_app_output_redir)
		dup2(lst_node->fd_app_output[i], STDOUT_FILENO);
	return (1);
}
