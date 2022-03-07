/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:14:03 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/07 11:38:06 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	open_files(t_cmd_lst **lst_node)
{
	t_cmd_lst	*start;

	start = *lst_node;
	while (*lst_node)
	{
		if ((*lst_node)->n_input_redir > 0)
			open_infiles(*lst_node);
		if ((*lst_node)->n_output_redir > 0)
			open_outfiles(*lst_node);
		if ((*lst_node)->n_app_output_redir > 0)
			open_app_outfiles(*lst_node);
		*lst_node = (*lst_node)->next;
	}
	*lst_node = start;
	return (0);
}

int	open_infiles(t_cmd_lst *lst_node)
{
	int	i;

	lst_node->fd_input = safe_malloc(sizeof(int), lst_node->n_input_redir);
	i = -1;
	while (++i < lst_node->n_input_redir)
	{
		lst_node->fd_input[i] = open(lst_node->input_redir[i], O_RDONLY);
		if (lst_node->fd_input[i] < 0)
		{
			perror(lst_node->input_redir[i]);
			if (lst_node->next == NULL)
				exit(0);
			else
				break ;
		}
	}
	return (0);
}

int	open_outfiles(t_cmd_lst *lst_node)
{
	int	i;

	lst_node->fd_output = safe_malloc(sizeof(int), lst_node->n_output_redir);
	i = -1;
	while (++i < lst_node->n_output_redir)
	{
		lst_node->fd_output[i] = open(lst_node->output_redir[i], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (lst_node->fd_output[i] < 0)
		{
			perror(lst_node->output_redir[i]);
			exit(0);
		}
	}
	return (0);
}

int	open_app_outfiles(t_cmd_lst *lst_node)
{
	int	i;

	lst_node->fd_app_output = safe_malloc(sizeof(int), lst_node->n_app_output_redir);
	i = -1;
	while (++i < lst_node->n_app_output_redir)
	{
		lst_node->fd_app_output[i] = open(lst_node->app_output_redir[i], O_CREAT | O_RDWR | O_APPEND, 0644);
		if (lst_node->fd_app_output[i] < 0)
		{
			perror(lst_node->app_output_redir[i]);
			exit(0);
		}
	}
	return (0);
}
