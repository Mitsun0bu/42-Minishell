/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:07:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/16 19:08:58 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char **av, char **envp)
{
	t_input		input;
	t_cmd_lst	*lst_head;

	(void)av;
	(void)envp;
	lst_head = NULL;
	if (ac > 1)
	{
		printf("To start our shell, use : ./minishell !\n");
		return (1);
	}
	init_shell();
	get_history(&input);
	ft_memset(&input, 0, sizeof(input));
	// ft_memset(&lst_head, 0, sizeof(lst_head));
	while (1)
	{
		cmd_line_handler(&input);
		lexer(&input);
		parser(&input);
		init_cmd_lst(&input, &lst_head);
		printf("cmd_index = %d\n", lst_head->cmd_index);
		printf("n_input_redir = %d\n", lst_head->n_input_redir);
		printf("input[1] = %s\n", lst_head->input_redir[1]);
		printf("n_output_redir = %d\n", lst_head->n_output_redir);
		printf("output[1] = %s\n", lst_head->output_redir[1]);
		printf("n_app_output_redir = %d\n", lst_head->n_app_output_redir);
		printf("app_output[1] = %s\n", lst_head->app_output_redir[1]);
		printf("n_heredoc = %d\n", lst_head->n_heredoc);
		printf("heredoc[1] = %s\n", lst_head->heredoc[1]);
		// executer(&input, av, envp);
	}
	free_struct(&input);
	return (0);
}

int	init_cmd_lst(t_input *input, t_cmd_lst **lst_head)
{
	int	i;

	i = -1;
	while(++i < input->n_cmd)
		add_node_back(lst_head, create_new_node(&i, input));
	return (0);
}

void	add_node_back(t_cmd_lst **lst_head, t_cmd_lst *new)
{
	t_cmd_lst	*last_node;

	if (!*lst_head)
		*lst_head = new;
	else
	{
		last_node = is_last_node(*lst_head);
		last_node->next = new;
	}
}

t_cmd_lst	*is_last_node(t_cmd_lst *lst_head)
{
	if (!lst_head)
		return (NULL);
	while (lst_head->next)
		lst_head = lst_head->next;
	return (lst_head);
}

t_cmd_lst	*create_new_node(int *i, t_input *input)
{
	t_cmd_lst	*new_node;


	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->cmd_index = *i;
	new_node->name = ft_strdup(input->cmd_exec_tab[*i][0]);
	node_input_redir_manager(i, new_node, input);
	node_output_redir_manager(i, new_node, input);
	node_app_output_redir_manager(i, new_node, input);
	node_heredoc_manager(i, new_node, input);
	new_node->next = NULL;
	return (new_node);
}

int	node_input_redir_manager(int *i, t_cmd_lst *new_node, t_input *input)
{
	int			i_r;

	i_r = 0;
	while(input->redir_tab[*i][0][i_r])
		i_r ++;
	new_node->n_input_redir = i_r;
	new_node->input_redir = malloc(sizeof(char *) * (i_r + 1));
	if(!new_node->input_redir)
		return (1);
	if (i_r == 0)
	{
		new_node->input_redir[i_r] = ft_strdup("");
		return (0);
	}
	new_node->input_redir[i_r] = 0;
	i_r = -1;
	while(input->redir_tab[*i][0][++i_r])
		new_node->input_redir[i_r] = ft_strdup(input->redir_tab[*i][0][i_r]);
	return (0);
}

int	node_output_redir_manager(int *i, t_cmd_lst *new_node, t_input *input)
{
	int			i_r;

	i_r = 0;
	while(input->redir_tab[*i][1][i_r])
		i_r ++;
	new_node->n_output_redir = i_r;
	new_node->output_redir = malloc(sizeof(char *) * (i_r + 1));
	if(!new_node->output_redir)
		return (1);
	if (i_r == 0)
	{
		new_node->output_redir[i_r] = ft_strdup("");
		return (0);
	}
	new_node->output_redir[i_r] = 0;
	i_r = -1;
	while(input->redir_tab[*i][1][++i_r])
		new_node->output_redir[i_r] = ft_strdup(input->redir_tab[*i][1][i_r]);
	return (0);
}

int	node_app_output_redir_manager(int *i, t_cmd_lst *new_node, t_input *input)
{
	int			i_r;

	i_r = 0;
	while(input->redir_tab[*i][2][i_r])
		i_r ++;
	new_node->n_app_output_redir = i_r;
	new_node->app_output_redir = malloc(sizeof(char *) * (i_r + 1));
	if(!new_node->app_output_redir)
		return (1);
	if (i_r == 0)
	{
		new_node->app_output_redir[i_r] = ft_strdup("");
		return (0);
	}
	new_node->app_output_redir[i_r] = 0;
	i_r = -1;
	while(input->redir_tab[*i][2][++i_r])
		new_node->app_output_redir[i_r] = ft_strdup(input->redir_tab[*i][2][i_r]);
	return (0);
}

int	node_heredoc_manager(int *i, t_cmd_lst *new_node, t_input *input)
{
	int			i_r;

	i_r = 0;
	while(input->redir_tab[*i][3][i_r])
		i_r ++;
	new_node->n_heredoc = i_r;
	new_node->heredoc = malloc(sizeof(char *) * (i_r + 1));
	if(!new_node->heredoc)
		return (1);
	if (i_r == 0)
	{
		new_node->heredoc[i_r] = ft_strdup("");
		return (0);
	}
	new_node->heredoc[i_r] = 0;
	i_r = -1;
	while(input->redir_tab[*i][3][++i_r])
		new_node->heredoc[i_r] = ft_strdup(input->redir_tab[*i][3][i_r]);
	return (0);
}

// printf("i = %d, cmd_index = %d, i_r = %d\n", *i, new_node->cmd_index, i_r);
// printf("n_input_redir = %d\n", new_node->n_input_redir);