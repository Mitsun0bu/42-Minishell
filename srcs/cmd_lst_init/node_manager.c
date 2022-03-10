/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:57:53 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/10 14:58:52 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
ATTENTION !!!!
Ici il faudra peut-être gerer les doublons dans les nom de fichier des redirections
*/

int	node_args_manager(int *i, t_cmd_lst *new_node, t_input *input)
{
	int	i_arg;

	i_arg = 0;
	while (input->cmd_exec_tab[*i][i_arg])
		i_arg ++;
	new_node->n_args = i_arg;
	new_node->cmd_args = safe_malloc(sizeof(char *), (i_arg + 1));
	if (i_arg == 0)
	{
		new_node->cmd_args[i_arg] = 0;
		return (0);
	}
	new_node->cmd_args[i_arg] = 0;
	i_arg = -1;
	while (input->cmd_exec_tab[*i][++i_arg])
		new_node->cmd_args[i_arg] = ft_strdup(input->cmd_exec_tab[*i][i_arg]);
	return (0);
}

int	node_input_redir_manager(int *i, t_cmd_lst *new_node, t_input *input)
{
	int			i_r;

	i_r = 0;
	while (input->redir_tab[*i][0][i_r])
		i_r ++;
	new_node->n_input_redir = i_r;
	new_node->input_redir = safe_malloc(sizeof(char *), (i_r + 1));
	if (i_r == 0)
	{
		new_node->input_redir[i_r] = 0;
		return (0);
	}
	new_node->input_redir[i_r] = 0;
	i_r = -1;
	while (input->redir_tab[*i][0][++i_r])
		new_node->input_redir[i_r] = ft_strdup(input->redir_tab[*i][0][i_r]);
	return (0);
}

int	node_output_redir_manager(int *i, t_cmd_lst *new_node, t_input *input)
{
	int			i_r;

	i_r = 0;
	while (input->redir_tab[*i][1][i_r])
		i_r ++;
	new_node->n_output_redir = i_r;
	new_node->output_redir = safe_malloc(sizeof(char *), (i_r + 1));
	if (i_r == 0)
	{
		new_node->output_redir[i_r] = 0;
		return (0);
	}
	new_node->output_redir[i_r] = 0;
	i_r = -1;
	while (input->redir_tab[*i][1][++i_r])
		new_node->output_redir[i_r] = ft_strdup(input->redir_tab[*i][1][i_r]);
	return (0);
}

int	node_heredoc_manager(int *i, t_cmd_lst *new_node, t_input *input)
{
	int			i_r;

	i_r = 0;
	while (input->redir_tab[*i][2][i_r])
		i_r ++;
	new_node->n_heredoc = i_r;
	new_node->heredoc = safe_malloc(sizeof(char *), (i_r + 1));
	if (i_r == 0)
	{
		new_node->heredoc[i_r] = 0;
		return (0);
	}
	new_node->heredoc[i_r] = 0;
	i_r = -1;
	while (input->redir_tab[*i][2][++i_r])
		new_node->heredoc[i_r] = ft_strdup(input->redir_tab[*i][2][i_r]);
	return (0);
}

int	node_app_output_redir_manager(int *i, t_cmd_lst *new_node, t_input *input)
{
	int			i_r;

	i_r = 0;
	while (input->redir_tab[*i][3][i_r])
		i_r ++;
	new_node->n_app_output_redir = i_r;
	new_node->app_output_redir = safe_malloc(sizeof(char *), (i_r + 1));
	if (i_r == 0)
	{
		new_node->app_output_redir[i_r] = 0;
		return (0);
	}
	new_node->app_output_redir[i_r] = 0;
	i_r = -1;
	while (input->redir_tab[*i][3][++i_r])
		new_node->app_output_redir[i_r] = ft_strdup(input->redir_tab[*i][3][i_r]);
	return (0);
}
