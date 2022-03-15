/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_redir_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:07:47 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/15 11:30:14 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	handle_output_redir(t_input *input, t_cmd_lst *cmd)
{
	int	redir_out;

	redir_out = 0;
	if (input->last_output_redir_tab[cmd->index] == TRUNC_OUTPUT)
	{
		if (cmd->n_app_output_redir)
			redir_out = dup_redir_app_output(cmd);
		redir_out = dup_redir_output(cmd);
	}
	else if (input->last_output_redir_tab[cmd->index] == APP_OUTPUT)
	{
		if (cmd->n_app_output_redir)
			redir_out = dup_redir_output(cmd);
		redir_out = dup_redir_app_output(cmd);
	}
	return (redir_out);
}

int	dup_redir_output(t_cmd_lst *cmd)
{
	int	i;

	i = -1;
	while (++i < cmd->n_output_redir)
		dup2(cmd->fd_output[i], STDOUT_FILENO);
	return (1);
}

int	dup_redir_app_output(t_cmd_lst *cmd)
{
	int	i;

	i = -1;
	while (++i < cmd->n_app_output_redir)
		dup2(cmd->fd_app_output[i], STDOUT_FILENO);
	return (1);
}