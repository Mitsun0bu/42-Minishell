/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:32:58 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/03 11:58:33 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	open_all_pipes(t_cmd_lst **lst_node)
{
	t_cmd_lst	*start;
	int 		i;

	i = -1;
	start = *lst_node;
	while (*lst_node)
	{
		open_single_pipe((*lst_node)->pipe_fd_tab);
		if ((*lst_node)->next == NULL)
			break;
		*lst_node = (*lst_node)->next;
	}
	*lst_node = start;
}

void	open_single_pipe(int *fd_tab)
{
	if (pipe(fd_tab) == -1)
	{
		perror("");
		exit (1);
	}
}

void	close_all_pipes(t_cmd_lst *lst_node)
{
	int i;

	i = -1;
	while (lst_node->previous)
		lst_node = lst_node->previous;
	while (lst_node)
	{
		close_single_pipe(lst_node->pipe_fd_tab);
		lst_node = lst_node->next;
	}
}

void	close_single_pipe(int *fd_tab)
{
	close(fd_tab[0]);
	close(fd_tab[1]);
}