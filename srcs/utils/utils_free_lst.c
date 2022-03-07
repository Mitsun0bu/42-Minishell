/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:09:53 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/07 11:46:53 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_lst(t_input *input, t_cmd_lst	**lst_node)
{
	t_cmd_lst	*current;
	t_cmd_lst	*next;

	if (!lst_node)
		return ;
	current = *lst_node;
	while (current)
	{
		next = current->next;
		free_node(input, current);
		current = next;
	}
	*lst_node = NULL;
}

void	free_node(t_input *input, t_cmd_lst *lst_node)
{
	if (!lst_node)
		return ;
	ft_free (lst_node->cmd_name);
	free_double (lst_node->cmd_args);
	free_double (lst_node->input_redir);
	if (input->n_cmd > 1)
		ft_free(lst_node->fd_input);
	free_double (lst_node->output_redir);
	if (input->n_cmd > 1)
		ft_free(lst_node->fd_output);
	free_double (lst_node->app_output_redir);
	if (input->n_cmd > 1)
		ft_free(lst_node->fd_app_output);
	free_double (lst_node->heredoc);
	ft_free (lst_node->valid_path);
	ft_free (lst_node);
}
