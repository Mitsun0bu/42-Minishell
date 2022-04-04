/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:23:59 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/04 17:06:59 by llethuil         ###   ########lyon.fr   */
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

	// ---------------- FINAL TEST ---------------- //
	// printf("======================= CMD_LST_INIT =======================\n");
	// printf("-------------------------------------------\n");
	// t_cmd_lst	*start;
	// start = cmd;
	// cmd = start;
	// while(cmd)
	// {
	// 	printf("| cmd index\t\t=\t%d\n", cmd->index);
	// 	printf("| cmd name\t\t=\t%s\n", cmd->name);
	// 	printf("| cmd n_args\t\t=\t%d\n", cmd->n_args);
	// 	i  = -1;
	// 	while (cmd->args[++i])
	// 		printf("| cmd args[%d]\t\t=\t%s\n", i, cmd->args[i]);
	// 	printf("| cmd n_infile\t\t=\t%d\n", cmd->n_infile);
	// 	printf("| cmd n_outfile\t\t=\t%d\n", cmd->n_outfile);
	// 	printf("| cmd n_heredoc\t\t=\t%d\n", cmd->n_heredoc);
	// 	printf("| cmd n_app_outfile\t=\t%d\n", cmd->n_app_outfile);
	// 	i  = -1;
	// 	while (cmd->infile[++i])
	// 		printf("| cmd infile #%d\t=\t%s\n", i, cmd->infile[i]);
	// 	i  = -1;
	// 	while (cmd->outfile[++i])
	// 		printf("| cmd outfile #%d\t=\t%s\n", i, cmd->outfile[i]);
	// 	i  = -1;
	// 	while (cmd->del[++i])
	// 		printf("| cmd heredoc del #%d\t=\t%s\n", i, cmd->del[i]);
	// 	i  = -1;
	// 	while (cmd->app_outfile[++i])
	// 		printf("| cmd appending outfile #%d=\t%s\n", i, cmd->app_outfile[i]);
	// 	printf("-------------------------------------------\n");
	// 	cmd = cmd->next;
	// }
	// cmd = start;
	// printf("============================================================\n");
	// -------------------------------------------- //
}

t_cmd_lst	*create_new_cmd(t_input *input, int *i)
{
	t_cmd_lst	*new_cmd;

	new_cmd = ft_malloc(input, sizeof(t_cmd_lst), 1);
	input->garbage->type = CMD_LST;
	ft_memset(new_cmd, 0, sizeof(t_cmd_lst));
	new_cmd->index = *i;
	if (input->cmd_exec_tab[*i][0])
		new_cmd->name = clean_cmd_name(input, input->cmd_exec_tab[*i][0]);
	cmd_args_manager(input, i, new_cmd);
	cmd_infile_manager(input, i, new_cmd);
	cmd_outfile_manager(input, i, new_cmd);
	cmd_heredoc_manager(input, i, new_cmd);
	cmd_app_outfile_manager(input, i, new_cmd);
	return (new_cmd);
}
