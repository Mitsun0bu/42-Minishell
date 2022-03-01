/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:32:58 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/01 14:22:01 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	open_all_pipes(t_cmd_lst **lst_node)
{
	t_cmd_lst	*start;
	int 		i;

	i = -1;
	start = *lst_node;
	// printf(" - - - - - OPEN PIPE_FD TAB - - - - - \n");
	while (*lst_node)
	{
		// printf("| NODE INDEX = %d\n", (*lst_node)->cmd_index);
		if (pipe((*lst_node)->pipe_fd_tab) == -1)
		{
			perror("");
			exit (1);
		}
		// printf("| PIPE_FD[0] = %d, PIPE_FD[1] = %d\n", (*lst_node)->pipe_fd_tab[0], (*lst_node)->pipe_fd_tab[1]);
		// printf("| \n");
		if ((*lst_node)->next == NULL)
			break;
		*lst_node = (*lst_node)->next;
	}
	// printf(" - - - - - - - - - - - - - - - - - - - \n");
	*lst_node = start;
}

// void	close_all_pipes(t_cmd_lst **lst_node)
// {
// 	t_cmd_lst	*start;
// 	int i;
// 	i = -1;
// 	start = *lst_node;
// 	while (*lst_node)
// 	{
// 		printf("| \n");
// 		printf("| CLOSE PIPE_FD TAB #%d\n", ++i);
// 		printf("| NODE INDEX = %d\n", (*lst_node)->cmd_index);
// 		close_single_pipe((*lst_node)->pipe_fd_tab);
// 		printf("| PIPE_FD[0] = %d, PIPE_FD[1] = %d\n", (*lst_node)->pipe_fd_tab[0], (*lst_node)->pipe_fd_tab[1]);
// 		*lst_node = (*lst_node)->next;
// 	}
// 	*lst_node = start;
// }

void	close_all_pipes(t_cmd_lst *lst_node)
{
	int i;

	i = -1;
	while (lst_node->previous)
	{
		// printf("| NODE INDEX = %d\n", lst_node->cmd_index);
		lst_node = lst_node->previous;
	}
	while (lst_node)
	{
		// printf("| \n");
		// printf("| CLOSE PIPE_FD TAB #%d\n", ++i);
		// printf("| NODE INDEX = %d\n", lst_node->cmd_index);
		close(lst_node->pipe_fd_tab[0]);
		close(lst_node->pipe_fd_tab[1]);
		// printf("| PIPE_FD[0] = %d, PIPE_FD[1] = %d\n", lst_node->pipe_fd_tab[0], lst_node->pipe_fd_tab[1]);
		lst_node = lst_node->next;
	}
}