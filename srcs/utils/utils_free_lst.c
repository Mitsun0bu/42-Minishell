/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:09:53 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/07 16:23:37 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_lst(t_cmd_lst	**lst_node)
{
	t_cmd_lst	*current;
	t_cmd_lst	*next;

	if (!lst_node)
		return ;
	current = *lst_node;
	while (current)
	{
		next = current->next;
		free_node(current);
		current = next;
	}
	*lst_node = NULL;
}

void	free_node(t_cmd_lst *lst_node)
{
	if (!lst_node)
		return ;
	ft_free (lst_node->cmd_name);
	free_double (lst_node->cmd_args);
	ft_free (lst_node->valid_path);
	free_double (lst_node->input_redir);
	free_double (lst_node->output_redir);
	free_double (lst_node->app_output_redir);
	free_double (lst_node->heredoc);
	if (lst_node->n_input_redir > 0)
		ft_free(lst_node->fd_input);
	if (lst_node->n_output_redir > 0)
		ft_free(lst_node->fd_output);
	if (lst_node->n_app_output_redir > 0)
		ft_free(lst_node->fd_app_output);
	ft_free (lst_node);
}
