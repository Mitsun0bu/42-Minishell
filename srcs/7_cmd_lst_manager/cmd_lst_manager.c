/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:36:41 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/19 09:51:35 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	cmd_args_manager(t_input *input, int *i, t_cmd_lst *new_cmd)
{
	int	i_arg;

	i_arg = 0;
	while (input->cmd_exec_tab[*i][i_arg])
		i_arg ++;
	new_cmd->n_args = i_arg;
	new_cmd->args = ft_malloc(input, sizeof(char *), i_arg + 1);
	input->gb->type = CMD_LST;
	i_arg = -1;
	while (++i_arg < new_cmd->n_args)
	{
		new_cmd->args[i_arg] = clean_str(input, input->cmd_exec_tab[*i][i_arg]);
		input->gb->type = CMD_LST;
	}
	new_cmd->args[i_arg] = NULL;
}

void	cmd_infile_manager(t_input *input, int *i, t_cmd_lst *new_cmd)
{
	int	j;

	j = 0;
	while (input->redir_tab[*i][0][j])
		j ++;
	new_cmd->n_infile = j;
	new_cmd->infile = ft_calloc(input, sizeof(char *), j + 1);
	input->gb->type = CMD_LST;
	new_cmd->infile[j] = NULL;
	j = -1;
	while (input->redir_tab[*i][0][++j])
	{
		new_cmd->infile[j] = clean_str(input, input->redir_tab[*i][0][j]);
		input->gb->type = CMD_LST;
	}
}

void	cmd_outfile_manager(t_input *input, int *i, t_cmd_lst *new_cmd)
{
	int	j;

	j = 0;
	while (input->redir_tab[*i][1][j])
		j ++;
	new_cmd->n_outfile = j;
	new_cmd->outfile = ft_calloc(input, sizeof(char *), j + 1);
	input->gb->type = CMD_LST;
	new_cmd->outfile[j] = 0;
	j = -1;
	while (input->redir_tab[*i][1][++j])
	{
		new_cmd->outfile[j] = clean_str(input, input->redir_tab[*i][1][j]);
		input->gb->type = CMD_LST;
	}
}

void	cmd_heredoc_manager(t_input *input, int *i, t_cmd_lst *new_cmd)
{
	int	j;

	j = 0;
	while (input->redir_tab[*i][2][j])
		j ++;
	new_cmd->n_heredoc = j;
	new_cmd->del = ft_calloc(input, sizeof(char *), j + 1);
	input->gb->type = CMD_LST;
	new_cmd->del[j] = 0;
	j = -1;
	while (input->redir_tab[*i][2][++j])
	{
		new_cmd->del[j] = clean_str(input, input->redir_tab[*i][2][j]);
		input->gb->type = CMD_LST;
	}
}

void	cmd_app_outfile_manager(t_input *input, int *i, t_cmd_lst *new_cmd)
{
	int	j;

	j = 0;
	while (input->redir_tab[*i][3][j])
		j ++;
	new_cmd->n_app_outfile = j;
	new_cmd->app_outfile = ft_calloc(input, sizeof(char *), j + 1);
	input->gb->type = CMD_LST;
	new_cmd->app_outfile[j] = 0;
	j = -1;
	while (input->redir_tab[*i][3][++j])
	{
		new_cmd->app_outfile[j] = clean_str(input, input->redir_tab[*i][3][j]);
		input->gb->type = CMD_LST;
	}
}
