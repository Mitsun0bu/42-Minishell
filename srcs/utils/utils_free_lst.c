/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:09:53 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/18 16:03:26 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "main.h"

void	free_lst(t_cmd_lst	**lst_head)
{
	t_cmd_lst	*current;
	t_cmd_lst	*next;

	if (!lst_head)
		return ;
	current = *lst_head;
	while (current)
	{
		next = current->next;
		free_node(current);
		current = next;
	}
	*lst_head = NULL;
}

void	free_node(t_cmd_lst *lst_head)
{
	if (!lst_head)
		return ;
	free (lst_head->cmd_name);
	free_double (lst_head->cmd_args);
	free_double (lst_head->input_redir);
	free_double (lst_head->output_redir);
	free_double (lst_head->app_output_redir);
	free_double (lst_head->heredoc);
	// free (lst_head->valid_path);
	free (lst_head->next);
	free (lst_head->previous);
	free (lst_head);
}