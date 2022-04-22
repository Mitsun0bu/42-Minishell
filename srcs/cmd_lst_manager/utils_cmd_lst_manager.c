/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmd_lst_manager.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:35:14 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/08 14:49:59 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	add_cmd_back(t_cmd_lst *cmd, t_cmd_lst *new_cmd)
{
	t_cmd_lst	*start;
	t_cmd_lst	*last_cmd;

	start = cmd;
	last_cmd = find_last_cmd(cmd);
	last_cmd->next = new_cmd;
	new_cmd->previous = last_cmd;
	new_cmd->next = NULL;
	cmd = start;
}

t_cmd_lst	*find_last_cmd(t_cmd_lst *cmd)
{
	if (!cmd)
		return (NULL);
	while (cmd->next)
		cmd = cmd->next;
	return (cmd);
}
