/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_linked_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:25:12 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/15 11:34:58 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	add_cmd_back(t_cmd_lst **cmd, t_cmd_lst *new_cmd)
{
	t_cmd_lst	*last_cmd;

	if (!*cmd)
	{
		*cmd = new_cmd;
		new_cmd->previous = NULL;
	}
	else
	{
		last_cmd = find_last_cmd(*cmd);
		last_cmd->next = new_cmd;
		new_cmd->previous = last_cmd;
	}
}

t_cmd_lst	*find_last_cmd(t_cmd_lst *cmd)
{
	if (!cmd)
		return (NULL);
	while (cmd->next)
		cmd = cmd->next;
	return (cmd);
}

t_cmd_lst	*create_new_cmd(int *i, t_input *input)
{
	t_cmd_lst	*new_cmd;

	new_cmd = safe_malloc(sizeof(t_cmd_lst), 1);
	new_cmd->index = *i;
	new_cmd->name = ft_strdup(input->cmd_exec_tab[*i][0]);
	cmd_args_manager(i, new_cmd, input);
	// valid path init ???
	cmd_input_redir_manager(i, new_cmd, input);
	cmd_output_redir_manager(i, new_cmd, input);
	cmd_heredoc_manager(i, new_cmd, input);
	cmd_app_output_redir_manager(i, new_cmd, input);
	new_cmd->heredoc_str = ft_calloc(0, 0);
	new_cmd->next = NULL;
	return (new_cmd);
}
