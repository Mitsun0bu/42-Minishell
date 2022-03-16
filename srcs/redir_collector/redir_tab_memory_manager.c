/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_tab_memory_manager.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:14:37 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/16 14:30:44 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	malloc_all_cmd_in_redir_tab(t_input *input)
{
	input->redir_tab = safe_malloc(sizeof(char ***), (input->n_cmd + 1));
	input->redir_tab[input->n_cmd] = NULL;
	return (0);
}

int	malloc_redir_types_in_redir_tab(t_input *input)
{
	int	i_cmd;

	i_cmd = -1;
	while (input->cmd_tab[++i_cmd])
	{
		input->redir_tab[i_cmd] = safe_malloc(sizeof(char **), 5);
		input->redir_tab[i_cmd][4] = NULL;
	}
	return (0);
}

int	malloc_any_redir_in_redir_tab(t_input *input, int type)
{
	int	i_cmd;
	int	n_red;

	i_cmd = -1;
	while (input->cmd_tab[++i_cmd])
	{
		n_red = count_any_redir (input->cmd_tab[i_cmd], type);
		if (!n_red)
		{
			input->redir_tab[i_cmd][type] = safe_malloc(sizeof(char *), 2);
			input->redir_tab[i_cmd][type][0] = NULL;
		}
		else
		{
			input->redir_tab[i_cmd][type] = safe_malloc(sizeof(char *), (n_red + 1));
			input->redir_tab[i_cmd][type][n_red] = NULL;
		}
	}
	return (0);
}

int	malloc_any_filename_in_redir_tab(t_input *input, int type)
{
	int	i_cmd;
	int	i_red;
	int	len;

	i_cmd = -1;
	while (input->redir_tab[++i_cmd])
	{
		len = 0;
		i_red = -1;
		while (++i_red < count_any_redir(input->cmd_tab[i_cmd], type))
		{
			if (type == 0)
				len = count_input_name_len(input->cmd_tab[i_cmd], &i_red);
			if (type == 1)
				len = count_output_name_len(input->cmd_tab[i_cmd], &i_red);
			if (type == 2)
				len = count_delimiter_len(input->cmd_tab[i_cmd], &i_red);
			if (type == 0)
				len = count_app_output_name_len(input->cmd_tab[i_cmd], &i_red);
			input->redir_tab[i_cmd][type][i_red] = safe_malloc(sizeof(char), (len + 1));
			input->redir_tab[i_cmd][type][i_red][len] = '\0';
		}
	}
	return (0);
}