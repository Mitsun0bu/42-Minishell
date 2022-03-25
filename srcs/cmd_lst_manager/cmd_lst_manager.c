/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:36:41 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/25 16:28:17 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	cmd_args_manager(t_input *input, int *i, t_cmd_lst *new_cmd)
{
	int	i_arg;

	i_arg = 0;
	while (input->cmd_exec_tab[*i][i_arg])
		i_arg ++;
	new_cmd->n_args = i_arg;
	new_cmd->args = ft_calloc(input, sizeof(char *), i_arg + 1);
	input->garbage->type = CMD_LST;
	i_arg = -1;
	while (++i_arg < new_cmd->n_args)
	{
		new_cmd->args[i_arg] = ft_strdup(input, input->cmd_exec_tab[*i][i_arg]);
		input->garbage->type = CMD_LST;
	}
	new_cmd->args[i_arg] = NULL;
	return (0);
}

int	cmd_input_redir_manager(t_input *input, int *i, t_cmd_lst *new_cmd)
{
	int			i_r;

	i_r = 0;
	while (input->redir_tab[*i][0][i_r])
		i_r ++;
	new_cmd->n_input_redir = i_r;
	new_cmd->input_redir = ft_calloc(input, sizeof(char *), i_r + 1);
	input->garbage->type = CMD_LST;
	new_cmd->input_redir[i_r] = NULL;
	i_r = -1;
	while (input->redir_tab[*i][0][++i_r])
	{
		new_cmd->input_redir[i_r] = ft_strdup(input, input->redir_tab[*i][0][i_r]);
		input->garbage->type = CMD_LST;
	}
	return (0);
}

int	cmd_output_redir_manager(t_input *input, int *i, t_cmd_lst *new_cmd)
{
	int			i_r;

	i_r = 0;
	while (input->redir_tab[*i][1][i_r])
		i_r ++;
	new_cmd->n_output_redir = i_r;
	new_cmd->output_redir = ft_calloc(input, sizeof(char *), i_r + 1);
	input->garbage->type = CMD_LST;
	new_cmd->output_redir[i_r] = 0;
	i_r = -1;
	while (input->redir_tab[*i][1][++i_r])
	{
		new_cmd->output_redir[i_r] = ft_strdup(input, input->redir_tab[*i][1][i_r]);
		input->garbage->type = CMD_LST;
	}
	return (0);
}

int	cmd_heredoc_manager(t_input *input, int *i, t_cmd_lst *new_cmd)
{
	int			i_r;

	i_r = 0;
	while (input->redir_tab[*i][2][i_r])
		i_r ++;
	new_cmd->n_heredoc = i_r;
	new_cmd->del = ft_calloc(input, sizeof(char *), i_r + 1);
	input->garbage->type = CMD_LST;
	new_cmd->del[i_r] = 0;
	i_r = -1;
	while (input->redir_tab[*i][2][++i_r])
	{
		new_cmd->del[i_r] = ft_strdup(input, input->redir_tab[*i][2][i_r]);
		input->garbage->type = CMD_LST;
	}
	return (0);
}

int	cmd_app_output_redir_manager(t_input *input, int *i, t_cmd_lst *new_cmd)
{
	int			i_r;

	i_r = 0;
	while (input->redir_tab[*i][3][i_r])
		i_r ++;
	new_cmd->n_app_output_redir = i_r;
	new_cmd->app_output_redir = ft_calloc(input, sizeof(char *), i_r + 1);
	input->garbage->type = CMD_LST;
	new_cmd->app_output_redir[i_r] = 0;
	i_r = -1;
	while (input->redir_tab[*i][3][++i_r])
	{
		new_cmd->app_output_redir[i_r] = ft_strdup(input, input->redir_tab[*i][3][i_r]);
		input->garbage->type = CMD_LST;
	}
	return (0);
}
