/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_collector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:36:30 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/16 10:27:37 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	malloc_cmd_dimension(t_input *input);
static void	malloc_types_dimension_for_each_cmd(t_input *input);
static void	malloc_file_dimension_for_each_type(t_input *input, int i_c, int t);
static void	malloc_name_of_each_file(t_input *input, int i_c, int t, int i_f);

void	redir_collector(t_input *input)
{
	int	i_cmd;
	int	type;
	int	i_file;

	get_last_redir_types_tab(input);
	malloc_cmd_dimension(input);
	malloc_types_dimension_for_each_cmd(input);
	i_cmd = -1;
	while (++i_cmd < input->n_cmd)
	{
		type = -1;
		while (++type < 4)
			malloc_file_dimension_for_each_type(input, i_cmd, type);
		type = -1;
		while (++type < 4)
		{
			i_file = -1;
			while (++i_file < count_n_file(input->cmd_tab[i_cmd], type))
			{
				malloc_name_of_each_file(input, i_cmd, type, i_file);
				copy_filenames_in_redir_tab(input, i_cmd, type, i_file);
			}
		}
	}
}

static void	malloc_cmd_dimension(t_input *input)
{
	input->redir_tab = ft_malloc(input, sizeof(char ***), input->n_cmd + 1);
	input->redir_tab[input->n_cmd] = NULL;
	input->gb->type = INPUT_STRUCT;
}

static void	malloc_types_dimension_for_each_cmd(t_input *input)
{
	int	i_cmd;

	i_cmd = -1;
	while (input->cmd_tab[++i_cmd])
	{
		input->redir_tab[i_cmd] = ft_calloc(input, sizeof(char **), 5);
		input->gb->type = INPUT_STRUCT;
	}
}

static void	malloc_file_dimension_for_each_type(t_input *input, int i_c, int t)
{
	int	n_file;
	int	i;

	n_file = count_n_file(input->cmd_tab[i_c], t);
	i = n_file + 1;
	input->redir_tab[i_c][t] = ft_calloc(input, sizeof(char *), i);
	input->gb->type = INPUT_STRUCT;
}

static void	malloc_name_of_each_file(t_input *input, int i_c, int t, int i_f)
{
	int	len;

	len = 0;
	if (t == INFILE || t == HEREDOC)
		len = count_filename_len(input->cmd_tab[i_c], i_f, '<', t);
	else if (t == OUTFILE || t == APP_OUTFILE)
		len = count_filename_len(input->cmd_tab[i_c], i_f, '>', t);
	input->redir_tab[i_c][t][i_f] = ft_malloc(input, sizeof(char), len + 1);
	input->redir_tab[i_c][t][i_f][len] = '\0';
	input->gb->type = INPUT_STRUCT;
}
