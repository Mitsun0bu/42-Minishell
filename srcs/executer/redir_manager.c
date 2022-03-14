/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:45:14 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/14 16:39:20 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	handle_input_redir(t_cmd_lst *lst_node)
{
	int	redir_in;

	redir_in = 0;
	if (lst_node->n_input_redir)
		redir_in = dup_redir_input(lst_node);
	return (redir_in);
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
