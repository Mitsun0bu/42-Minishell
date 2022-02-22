/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:14:03 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/22 17:44:54 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	open_files(t_cmd_lst **lst_head)
{
	t_cmd_lst	*start;

	start = *lst_head;
	while (*lst_head)
	{
		if ((*lst_head)->n_input_redir > 0)
			open_infiles(*lst_head);
		if ((*lst_head)->n_output_redir > 0)
			open_outfiles(*lst_head);
		if ((*lst_head)->n_app_output_redir > 0)
			open_app_outfiles(*lst_head);
		*lst_head = (*lst_head)->next;
	}
	*lst_head = start;
	return (0);
}

int	open_infiles(t_cmd_lst *lst_head)
{
	int	i;

	printf("n_input_redir = %d\n", lst_head->n_input_redir);
	lst_head->fd_input = safe_malloc(sizeof(int), lst_head->n_input_redir);
	i = -1;
	while(++i < lst_head->n_input_redir)
	{
		lst_head->fd_input[i] = open(lst_head->input_redir[i], O_RDONLY);
		if (lst_head->fd_input[i] < 0)
		{
			perror(lst_head->input_redir[i]);
			if (lst_head->next == NULL)
				exit(0);
			else
				break;
		}
	}
	return (0);
}

int	open_outfiles(t_cmd_lst *lst_head)
{
	int	i;

	lst_head->fd_output = safe_malloc(sizeof(int), lst_head->n_output_redir);
	i = -1;
	while(++i < lst_head->n_output_redir)
	{
		lst_head->fd_output[i] = open(lst_head->output_redir[i], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (lst_head->fd_output[i] < 0)
		{
			perror(lst_head->output_redir[i]);
			exit(0);
		}
	}
	return (0);
}

int	open_app_outfiles(t_cmd_lst *lst_head)
{
	int	i;

	lst_head->fd_app_output = safe_malloc(sizeof(int), lst_head->n_app_output_redir);
	i = -1;
	while(++i < lst_head->n_app_output_redir)
	{
		lst_head->fd_app_output[i] = open(lst_head->app_output_redir[i], O_CREAT | O_RDWR | O_APPEND, 0644);
		if (lst_head->fd_app_output[i] < 0)
		{
			perror(lst_head->app_output_redir[i]);
			exit(0);
		}
	}
	return (0);
}