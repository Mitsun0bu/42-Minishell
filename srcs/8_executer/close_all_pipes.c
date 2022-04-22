/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_all_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:32:58 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/22 09:48:29 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	close_all_pipes(t_cmd_lst *cmd)
{
	int	i;

	i = -1;
	while (cmd->previous)
		cmd = cmd->previous;
	while (cmd)
	{
		close_single_pipe(cmd->cmd_pipe);
		if (cmd->n_heredoc)
			close_single_pipe(cmd->heredoc_pipe);
		cmd = cmd->next;
	}
}
