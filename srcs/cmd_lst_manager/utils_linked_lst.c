/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_linked_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:25:12 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/28 16:13:01 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	add_cmd_back(t_cmd_lst **cmd, t_cmd_lst *new_cmd)
{
	t_cmd_lst	*last_cmd;

	last_cmd = find_last_cmd(*cmd);
	last_cmd->next = new_cmd;
	new_cmd->previous = last_cmd;
}

t_cmd_lst	*find_last_cmd(t_cmd_lst *cmd)
{
	if (!cmd)
		return (NULL);
	while (cmd->next)
		cmd = cmd->next;
	return (cmd);
}

