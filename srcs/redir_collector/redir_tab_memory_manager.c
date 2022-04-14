/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_tab_memory_manager.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:14:37 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/14 11:05:15 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	malloc_cmd_dimension(t_input *input)
{
	input->redir_tab = ft_malloc(input, sizeof(char ***), input->n_cmd + 1);
	input->redir_tab[input->n_cmd] = NULL;
	input->gb->type = INPUT_STRUCT;
}

void	malloc_types_dimension_for_each_cmd(t_input *input)
{
	int	i_cmd;

	i_cmd = -1;
	while (input->cmd_tab[++i_cmd])
	{
		input->redir_tab[i_cmd] = ft_calloc(input, sizeof(char **), 5);
		input->gb->type = INPUT_STRUCT;
	}
}

void	malloc_n_file_dimension_for_each_type(t_input *input, int i_c, int t)
{
	int	n_file;
	int	i;

	n_file = count_n_file(input->cmd_tab[i_c], t);
	i = n_file + 1;
	input->redir_tab[i_c][t] = ft_calloc(input, sizeof(char *), i);
	input->gb->type = INPUT_STRUCT;
}

void	malloc_name_for_each_file(t_input *input, int i_c, int t, int i_f)
{
	int	len;

	len = 0;
	if (t == INFILE)
		len = count_infile_name_len(input->cmd_tab[i_c], i_f);
	else if (t == OUTFILE)
		len = count_output_name_len(input->cmd_tab[i_c], i_f);
	else if (t == HEREDOC)
		len = count_delimiter_len(input->cmd_tab[i_c], i_f);
	else if (t == APP_OUTFILE)
		len = count_app_output_name_len(input->cmd_tab[i_c], i_f);
	input->redir_tab[i_c][t][i_f] = ft_malloc(input, sizeof(char), len + 1);
	input->redir_tab[i_c][t][i_f][len] = '\0';
	input->gb->type = INPUT_STRUCT;
}
