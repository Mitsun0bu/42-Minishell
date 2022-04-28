/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_collector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:36:30 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/28 18:46:44 by llethuil         ###   ########lyon.fr   */
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
printf("===================== REDIR_COLLECTOR ======================\n");
printf("|\t\t~~~~~ REDIR TAB ~~~~~\n");
int	i = -1;
while(input->redir_tab[++i])
{
	printf("| COMMAND #%d\n", i);
	int j = -1;
	while (input->redir_tab[i][++j])
	{
		printf("|\t-------------------------------------\n");
		printf("|\tREDIRECTION TYPE : %d\n", j);
		int	k = -1;
		while(input->redir_tab[i][j][++k])
		{
			printf("|\t\t-----------------------------\n");
			printf("|\t\tREDIRECTION INDEX : %d\n", k);
			printf("|\t\t\tREDIRECTION FILE NAME : %s\n",input->redir_tab[i][j][k]);
		}
	}
}
printf("|\n");
printf("|\t\t~~~~~ LAST_REDIR_TYPE TAB ~~~~~\n");
i = -1;
while(input->redir_tab[++i])
{
	printf("| COMMAND #%d\n", i);
	printf("| LAST_infile_TYPE : %d\n", input->last_infile_type[i]);
	printf("| LAST_outfile_TYPE : %d\n", input->last_outfile_type[i]);
}
printf("============================================================\n");
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
	printf("n_file = %d\n", n_file);
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
	{
		len = count_filename_len(input->cmd_tab[i_c], i_f, '>', t);
		if (t == OUTFILE)
			printf("OUTFILE len = %d\n", len);
		else if (t == APP_OUTFILE)
			printf("APP_OUTFILE len = %d\n", len);
	}
	input->redir_tab[i_c][t][i_f] = ft_malloc(input, sizeof(char), len + 1);
	input->redir_tab[i_c][t][i_f][len] = '\0';
	input->gb->type = INPUT_STRUCT;
}
