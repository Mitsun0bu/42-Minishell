/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:09:53 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/16 18:06:06 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_lst(t_cmd_lst	**cmd)
{
	t_cmd_lst	*current;
	t_cmd_lst	*next;

	if (!cmd)
		return ;
	current = *cmd;
	while (current)
	{
		next = current->next;
		free_cmd(current);
		current = next;
	}
	*cmd = NULL;
}

void	free_cmd(t_cmd_lst *cmd)
{
	if (!cmd)
		return ;
	ft_free((void *)&cmd->name);
	free_double (cmd->args);
	ft_free((void *)&cmd->valid_path);
	free_double (cmd->input_redir);
	free_double (cmd->output_redir);
	free_double (cmd->app_output_redir);
	free_double (cmd->del);
	if (cmd->n_input_redir > 0)
		ft_free((void *)&cmd->fd_input);
	if (cmd->n_output_redir > 0)
		ft_free((void *)&cmd->fd_output);
	if (cmd->n_app_output_redir > 0)
		ft_free((void *)&cmd->fd_app_output);
	ft_free((void *)&cmd->heredoc_str);
	ft_free((void *)&cmd);
}
