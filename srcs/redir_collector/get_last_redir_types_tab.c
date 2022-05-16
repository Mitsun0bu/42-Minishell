/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_redir_types_tab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:48:00 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/16 09:44:45 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	init_last_redir_types_tab(t_input *input);
static void	get_last_redir_types(t_input *input, char *cmd, int i_cmd, int *i);

void	get_last_redir_types_tab(t_input *input)
{
	int	i_cmd;
	int	i;

	init_last_redir_types_tab(input);
	i_cmd = -1;
	while (++i_cmd < input->n_cmd)
	{
		i = ft_strlen(input->cmd_tab[i_cmd]);
		while (--i >= 0)
			get_last_redir_types(input, input->cmd_tab[i_cmd], i_cmd, &i);
	}
}

static void	init_last_redir_types_tab(t_input *input)
{
	int	i_cmd;

	i_cmd = -1;
	input->last_infile_type = ft_calloc(input, sizeof(int), input->n_cmd);
	input->gb->type = INPUT_STRUCT;
	input->last_outfile_type = ft_calloc(input, sizeof(int), input->n_cmd);
	input->gb->type = INPUT_STRUCT;
	while (++i_cmd < input->n_cmd)
	{
		input->last_infile_type[i_cmd] = UNSET;
		input->last_outfile_type[i_cmd] = UNSET;
	}
}

static void	get_last_redir_types(t_input *input, char *cmd, int i_cmd, int *i)
{
	if (cmd[*i] == '\'' || cmd[*i] == '"')
		back_skip_quotes(cmd, i);
	if (input->last_infile_type[i_cmd] == UNSET)
	{
		if ((*i == 0 && cmd[*i] == '<')
			|| (cmd[*i] == '<' && cmd[*i - 1] != '<'))
			input->last_infile_type[i_cmd] = INFILE;
		else if ((*i == 0 && cmd[*i] == '<')
			|| (cmd[*i] == '<' && cmd[*i - 1] == '<'))
			input->last_infile_type[i_cmd] = HEREDOC;
	}
	if (input->last_outfile_type[i_cmd] == UNSET)
	{
		if ((*i == 0 && cmd[*i] == '>')
			|| (cmd[*i] == '>' && cmd[*i - 1] != '>'))
			input->last_outfile_type[i_cmd] = OUTFILE;
		else if ((*i == 0 && cmd[*i] == '>')
			|| (cmd[*i] == '>' && cmd[*i - 1] == '>'))
			input->last_outfile_type[i_cmd] = APP_OUTFILE;
	}
}
