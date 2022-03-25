/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_tab_memory_manager.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:14:37 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/24 16:45:26 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	malloc_cmd_dimension(t_input *input)
{
	input->redir_tab = ft_malloc(input, sizeof(char ***), input->n_cmd + 1);
	input->redir_tab[input->n_cmd] = NULL;
	input->garbage->type = INPUT_STRUCT;
	return (0);
}

int	malloc_types_dimension_for_each_cmd(t_input *input)
{
	int	i_cmd;

	i_cmd = -1;
	while (input->cmd_tab[++i_cmd])
	{
		input->redir_tab[i_cmd] = ft_malloc(input, sizeof(char **), 5);
		input->redir_tab[i_cmd][4] = NULL;
		input->garbage->type = INPUT_STRUCT;
	}
	return (0);
}

int	malloc_n_file_dimension_for_each_type(t_input *input, int i_cmd, int type)
{
	int	n_file;
	int	i;

	n_file = count_n_file(input->cmd_tab[i_cmd], type);
	i = n_file + 1;
	input->redir_tab[i_cmd][type] = ft_malloc(input, sizeof(char *), i);
	input->redir_tab[i_cmd][type][0] = NULL;
	input->garbage->type = INPUT_STRUCT;
	return (0);
}

int	malloc_name_for_each_file(t_input *input, int i_cmd, int type, int i_file)
{
	int	len;

	len = 0;
	if (type == 0)
		len = count_infile_name_len(input->cmd_tab[i_cmd], i_file);
	if (type == 1)
		len = count_output_name_len(input->cmd_tab[i_cmd], i_file);
	if (type == 2)
		len = count_delimiter_len(input->cmd_tab[i_cmd], i_file);
	if (type == 3)
		len = count_app_output_name_len(input->cmd_tab[i_cmd], i_file);
	len ++;
	input->redir_tab[i_cmd][type][i_file] = ft_malloc(input, sizeof(char), len);
	input->redir_tab[i_cmd][type][i_file][len - 1] = '\0';
	input->garbage->type = INPUT_STRUCT;
	return (0);
}
