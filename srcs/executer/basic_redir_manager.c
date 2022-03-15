/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_redir_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:07:06 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/15 15:01:57 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	handle_input_redir(t_cmd_lst *cmd)
{
	int	i;

	i = -1;
	if (cmd->n_input_redir)
		while (++i < cmd->n_input_redir)
			dup2(cmd->fd_input[i], STDIN_FILENO);
	return (i);
}

int	handle_output_redir(t_input *input, t_cmd_lst *cmd)
{
	int	i;

	i = -1;
	if (input->last_output_redir_tab[cmd->index] == TRUNC_OUTPUT)
	{
		if (cmd->n_app_output_redir)
			while (++i < cmd->n_app_output_redir)
				dup2(cmd->fd_app_output[i], STDOUT_FILENO);
		i = -1;
		while (++i < cmd->n_output_redir)
			dup2(cmd->fd_output[i], STDOUT_FILENO);
	}
	else if (input->last_output_redir_tab[cmd->index] == APP_OUTPUT)
	{
		if (cmd->n_output_redir)
			while (++i < cmd->n_output_redir)
				dup2(cmd->fd_output[i], STDOUT_FILENO);
		i = -1;
		while (++i < cmd->n_app_output_redir)
				dup2(cmd->fd_app_output[i], STDOUT_FILENO);
	}
	return (i);
}