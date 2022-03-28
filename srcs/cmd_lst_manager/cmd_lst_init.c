/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:23:59 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/28 16:13:47 by llethuil         ###   ########lyon.fr   */
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

	// ---------------- FINAL TEST ---------------- //
	printf("======================= CMD_LST_INIT =======================\n");
	printf("-------------------------------------------\n");
	t_cmd_lst	*start;
	start = *cmd;
	*cmd = start;
	while(*cmd)
	{
		printf("| cmd index\t\t=\t%d\n", (*cmd)->index);
		printf("| cmd name\t\t=\t%s\n", (*cmd)->name);
		printf("| cmd n_args\t\t=\t%d\n", (*cmd)->n_args);
		i  = -1;
		while ((*cmd)->args[++i])
			printf("| cmd args[%d]\t\t=\t%s\n", i, (*cmd)->args[i]);
		printf("| cmd n_infile\t\t=\t%d\n", (*cmd)->n_input_redir);
		printf("| cmd n_outfile\t\t=\t%d\n", (*cmd)->n_output_redir);
		printf("| cmd n_heredoc\t\t=\t%d\n", (*cmd)->n_heredoc);
		printf("| cmd n_app_outfile\t=\t%d\n", (*cmd)->n_app_output_redir);
		i  = -1;
		while ((*cmd)->input_redir[++i])
			printf("| cmd infile #%d\t=\t%s\n", i, (*cmd)->input_redir[i]);
		i  = -1;
		while ((*cmd)->output_redir[++i])
			printf("| cmd outfile #%d\t=\t%s\n", i, (*cmd)->output_redir[i]);
		i  = -1;
		while ((*cmd)->del[++i])
			printf("| cmd heredoc del #%d\t=\t%s\n", i, (*cmd)->del[i]);
		i  = -1;
		while ((*cmd)->app_output_redir[++i])
			printf("| cmd appending outfile #%d=\t%s\n", i, (*cmd)->app_output_redir[i]);
		printf("| cmd path\t\t=\t%s\n", (*cmd)->valid_path);
		printf("-------------------------------------------\n");
		*cmd = (*cmd)->next;
	}
	*cmd = start;
	printf("============================================================\n");
	// -------------------------------------------- //
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
		printf("new_cmd->name = %s\n", new_cmd->name);
		input->garbage->type = CMD_LST;
	}
	else
		new_cmd->name = NULL;
	cmd_args_manager(input, i, new_cmd);
	cmd_input_redir_manager(input, i, new_cmd);
	cmd_output_redir_manager(input, i, new_cmd);
	cmd_heredoc_manager(input, i, new_cmd);
	cmd_app_output_redir_manager(input, i, new_cmd);
	new_cmd->valid_path = NULL;
	new_cmd->fd_input = NULL;
	new_cmd->fd_output = NULL;
	new_cmd->fd_app_output = NULL;
	new_cmd->heredoc_str = NULL;
	new_cmd->next = NULL;
	new_cmd->previous = NULL;
	return (new_cmd);
}
