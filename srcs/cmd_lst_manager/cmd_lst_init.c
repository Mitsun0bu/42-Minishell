/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:23:59 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/12 15:39:44 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	cmd_lst_init(t_input *input, t_cmd_lst **cmd)
{
	int	i;

	i = 0;
	*cmd = create_new_cmd(input, &i);
	while (++i < input->n_cmd)
		add_cmd_back(*cmd, create_new_cmd(input, &i));
}

t_cmd_lst	*create_new_cmd(t_input *input, int *i)
{
	t_cmd_lst	*new_cmd;

	new_cmd = ft_malloc(input, sizeof(t_cmd_lst), 1);
	input->gb->type = CMD_LST;
	ft_memset(new_cmd, 0, sizeof(t_cmd_lst));
	new_cmd->i = *i;
	if (input->cmd_exec_tab && input->cmd_exec_tab[*i][0])
		new_cmd->name = clean_str(input, input->cmd_exec_tab[*i][0]);
	cmd_args_manager(input, i, new_cmd);
	cmd_infile_manager(input, i, new_cmd);
	cmd_outfile_manager(input, i, new_cmd);
	cmd_heredoc_manager(input, i, new_cmd);
	cmd_app_outfile_manager(input, i, new_cmd);
	return (new_cmd);
}
