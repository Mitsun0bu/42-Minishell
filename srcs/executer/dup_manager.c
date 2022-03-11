/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:09:30 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/11 18:51:15 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

void	dup_heredoc(char *heredoc_str)
{
	int	pipe_fd_heredoc[2];

	open_single_pipe(pipe_fd_heredoc);
	ft_putstr_fd(heredoc_str, pipe_fd_heredoc[1]);
	dup2(pipe_fd_heredoc[0], STDIN_FILENO);
	close_single_pipe(pipe_fd_heredoc);
}