/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_linked_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:25:12 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/10 13:55:09 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	add_node_back(t_cmd_lst **lst_node, t_cmd_lst *new_node)
{
	t_cmd_lst	*last_node;

	if (!*lst_node)
	{
		*lst_node = new_node;
		new_node->previous = NULL;
	}
	else
	{
		last_node = is_last_node(*lst_node);
		last_node->next = new_node;
		new_node->previous = last_node;
	}
}

t_cmd_lst	*is_last_node(t_cmd_lst *lst_node)
{
	if (!lst_node)
		return (NULL);
	while (lst_node->next)
		lst_node = lst_node->next;
	return (lst_node);
}

t_cmd_lst	*create_new_node(int *i, t_input *input)
{
	t_cmd_lst	*new_node;

	new_node = safe_malloc(sizeof(t_cmd_lst), 1);
	new_node->cmd_index = *i;
	new_node->cmd_name = ft_strdup(input->cmd_exec_tab[*i][0]);
	node_args_manager(i, new_node, input);
	node_input_redir_manager(i, new_node, input);
	node_output_redir_manager(i, new_node, input);
	node_heredoc_manager(i, new_node, input);
	node_app_output_redir_manager(i, new_node, input);
	new_node->next = NULL;
	return (new_node);
}
