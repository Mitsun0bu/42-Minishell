/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:23:59 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/29 10:52:45 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	cmd_lst_init(t_input *input, t_cmd_lst **cmd)
{
	int	i;

	i = 0;
	*cmd = create_new_cmd(input, &i);
	while (++i < input->n_cmd)
		add_cmd_back(cmd, create_new_cmd(input, &i));
	return (0);
}

void	add_cmd_back(t_cmd_lst **cmd, t_cmd_lst *new_cmd)
{
	t_cmd_lst	*last_cmd;

	last_cmd = find_last_cmd(*cmd);
	last_cmd->next = new_cmd;
	new_cmd->previous = last_cmd;
	new_cmd->next = NULL;
}

t_cmd_lst	*find_last_cmd(t_cmd_lst *cmd)
{
	if (!cmd)
		return (NULL);
	while (cmd->next)
		cmd = cmd->next;
	return (cmd);
}

t_cmd_lst	*create_new_cmd(t_input *input, int *i)
{
	t_cmd_lst	*new_cmd;

	new_cmd = ft_malloc(input, sizeof(t_cmd_lst), 1);
	input->garbage->type = CMD_LST;
	new_cmd->index = *i;
	if (input->cmd_exec_tab[*i][0])
	{
		new_cmd->name = ft_strdup(input, input->cmd_exec_tab[*i][0]);
		printf("new_cmd->name = %s\n", new_cmd->name);
		input->garbage->type = CMD_LST;
	}
	else
		new_cmd->name = NULL;
	cmd_args_manager(input, i, new_cmd);
	cmd_infile_manager(input, i, new_cmd);
	cmd_outfile_manager(input, i, new_cmd);
	cmd_heredoc_manager(input, i, new_cmd);
	cmd_app_outfile_manager(input, i, new_cmd);
	new_cmd->valid_path = NULL;
	new_cmd->fd_input = NULL;
	new_cmd->fd_output = NULL;
	new_cmd->fd_app_output = NULL;
	new_cmd->heredoc_str = NULL;
	return (new_cmd);
}
