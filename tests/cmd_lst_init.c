/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:26:10 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/12 11:44:24 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

	// ---------------- FINAL TEST ---------------- //
	// printf("======================= CMD_LST_INIT =======================\n");
	// printf("-------------------------------------------\n");
	// t_cmd_lst	*start;
	// start = *cmd;
	// *cmd = start;
	// while(*cmd)
	// {
	// 	printf("| cmd index\t\t=\t%d\n", (*cmd)->i);
	// 	printf("| cmd name\t\t=\t%s\n", (*cmd)->name);
	// 	printf("| cmd n_args\t\t=\t%d\n", (*cmd)->n_args);
	// 	i  = -1;
	// 	while ((*cmd)->args[++i])
	// 		printf("| cmd args[%d]\t\t=\t%s\n", i, (*cmd)->args[i]);
	// 	printf("| cmd n_infile\t\t=\t%d\n", (*cmd)->n_infile);
	// 	printf("| cmd n_outfile\t\t=\t%d\n", (*cmd)->n_outfile);
	// 	printf("| cmd n_heredoc\t\t=\t%d\n", (*cmd)->n_heredoc);
	// 	printf("| cmd n_app_outfile\t=\t%d\n", (*cmd)->n_app_outfile);
	// 	i  = -1;
	// 	while ((*cmd)->infile[++i])
	// 		printf("| cmd infile[%d]\t\t=\t%s\n", i, (*cmd)->infile[i]);
	// 	i  = -1;
	// 	while ((*cmd)->outfile[++i])
	// 		printf("| cmd outfile[%d]\t=\t%s\n", i, (*cmd)->outfile[i]);
	// 	i  = -1;
	// 	while ((*cmd)->del[++i])
	// 		printf("| cmd heredoc del[%d]\t=\t%s\n", i, (*cmd)->del[i]);
	// 	i  = -1;
	// 	while ((*cmd)->app_outfile[++i])
	// 		printf("| cmd appending outfile[%d]\t=\t%s\n", i, (*cmd)->app_outfile[i]);
	// 	printf("| cmd path\t\t=\t%s\n", (*cmd)->valid_path);
	// 	printf("-------------------------------------------\n");
	// 	*cmd = (*cmd)->next;
	// }
	// *cmd = start;
	// printf("============================================================\n");
	// -------------------------------------------- //