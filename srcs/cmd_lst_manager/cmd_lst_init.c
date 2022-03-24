/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:23:59 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/24 11:01:28 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	cmd_lst_init(t_input *input, t_cmd_lst **cmd)
{
	int	i;

	i = -1;
	while (++i < input->n_cmd)
		add_cmd_back(cmd, create_new_cmd(input, &i));
	return (0);
}

t_cmd_lst	*create_new_cmd(t_input *input, int *i)
{
	t_cmd_lst	*new_cmd;

	new_cmd = ft_malloc(input, sizeof(t_cmd_lst), 1);
	input->garbage->type = CMD_LST;
	new_cmd->index = *i;
	if(input->cmd_exec_tab[*i][0])
	{
		new_cmd->name = ft_strdup(input, input->cmd_exec_tab[*i][0]);
		input->garbage->type = CMD_LST;
	}
	else
		new_cmd->name = NULL;
	cmd_args_manager(input, i, new_cmd);
	cmd_input_redir_manager(input, i, new_cmd);
	cmd_output_redir_manager(input, i, new_cmd);
	cmd_heredoc_manager(input, i, new_cmd);
	cmd_app_output_redir_manager(input, i, new_cmd);
	new_cmd->heredoc_str = NULL;
	new_cmd->next = NULL;
	new_cmd->previous = NULL;
	return (new_cmd);
}