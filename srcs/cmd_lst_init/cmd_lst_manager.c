/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:36:41 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/15 11:36:46 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
ATTENTION !!!!
Ici il faudra peut-être gerer les doublons dans les nom de fichier des redirections
*/

int	cmd_args_manager(int *i, t_cmd_lst *new_cmd, t_input *input)
{
	int	i_arg;

	i_arg = 0;
	while (input->cmd_exec_tab[*i][i_arg])
		i_arg ++;
	new_cmd->n_args = i_arg;
	new_cmd->args = safe_malloc(sizeof(char *), (i_arg + 1));
	if (i_arg == 0)
	{
		new_cmd->args[i_arg] = 0;
		return (0);
	}
	new_cmd->args[i_arg] = 0;
	i_arg = -1;
	while (input->cmd_exec_tab[*i][++i_arg])
		new_cmd->args[i_arg] = ft_strdup(input->cmd_exec_tab[*i][i_arg]);
	return (0);
}

int	cmd_input_redir_manager(int *i, t_cmd_lst *new_cmd, t_input *input)
{
	int			i_r;

	i_r = 0;
	while (input->redir_tab[*i][0][i_r])
		i_r ++;
	new_cmd->n_input_redir = i_r;
	new_cmd->input_redir = safe_malloc(sizeof(char *), (i_r + 1));
	if (i_r == 0)
	{
		new_cmd->input_redir[i_r] = 0;
		return (0);
	}
	new_cmd->input_redir[i_r] = 0;
	i_r = -1;
	while (input->redir_tab[*i][0][++i_r])
		new_cmd->input_redir[i_r] = ft_strdup(input->redir_tab[*i][0][i_r]);
	return (0);
}

int	cmd_output_redir_manager(int *i, t_cmd_lst *new_cmd, t_input *input)
{
	int			i_r;

	i_r = 0;
	while (input->redir_tab[*i][1][i_r])
		i_r ++;
	new_cmd->n_output_redir = i_r;
	new_cmd->output_redir = safe_malloc(sizeof(char *), (i_r + 1));
	if (i_r == 0)
	{
		new_cmd->output_redir[i_r] = 0;
		return (0);
	}
	new_cmd->output_redir[i_r] = 0;
	i_r = -1;
	while (input->redir_tab[*i][1][++i_r])
		new_cmd->output_redir[i_r] = ft_strdup(input->redir_tab[*i][1][i_r]);
	return (0);
}

int	cmd_heredoc_manager(int *i, t_cmd_lst *new_cmd, t_input *input)
{
	int			i_r;

	i_r = 0;
	while (input->redir_tab[*i][2][i_r])
		i_r ++;
	new_cmd->n_heredoc = i_r;
	new_cmd->del = safe_malloc(sizeof(char *), (i_r + 1));
	if (i_r == 0)
	{
		new_cmd->del[i_r] = 0;
		return (0);
	}
	new_cmd->del[i_r] = 0;
	i_r = -1;
	while (input->redir_tab[*i][2][++i_r])
		new_cmd->del[i_r] = ft_strdup(input->redir_tab[*i][2][i_r]);
	return (0);
}

int	cmd_app_output_redir_manager(int *i, t_cmd_lst *new_cmd, t_input *input)
{
	int			i_r;

	i_r = 0;
	while (input->redir_tab[*i][3][i_r])
		i_r ++;
	new_cmd->n_app_output_redir = i_r;
	new_cmd->app_output_redir = safe_malloc(sizeof(char *), (i_r + 1));
	if (i_r == 0)
	{
		new_cmd->app_output_redir[i_r] = 0;
		return (0);
	}
	new_cmd->app_output_redir[i_r] = 0;
	i_r = -1;
	while (input->redir_tab[*i][3][++i_r])
		new_cmd->app_output_redir[i_r] = ft_strdup(input->redir_tab[*i][3][i_r]);
	return (0);
}
