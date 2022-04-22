/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_all_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:48:30 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/22 09:48:46 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	open_all_pipes(t_cmd_lst *cmd)
{
	t_cmd_lst	*start;
	int			i;

	i = -1;
	start = cmd;
	while (cmd)
	{
		if (open_single_pipe(cmd->cmd_pipe) == FAILED)
			return (FAILED);
		if (cmd->next == NULL)
			break ;
		cmd = cmd->next;
	}
	cmd = start;
	return (0);
}