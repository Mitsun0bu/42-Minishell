/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_redir_types_tab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:48:00 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/19 09:39:29 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	get_last_redir_types_tab(t_input *input)
{
	int	i_cmd;
	int	i_start;

	init_last_redir_types_tab(input);
	i_cmd = -1;
	while (++i_cmd < input->n_cmd)
	{
		i_start = ft_strlen(input->cmd_tab[i_cmd]);
		while (--i_start >= 0)
			get_last_redir_types(input, input->cmd_tab[i_cmd], i_cmd, &i_start);
	}
}

void	init_last_redir_types_tab(t_input *input)
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

void	get_last_redir_types(t_input *input, char *cmd, int i_cmd, int *i_start)
{
	if (cmd[*i_start] == '\'' || cmd[*i_start] == '"')
		back_skip_quotes(cmd, i_start);
	if (input->last_infile_type[i_cmd] == UNSET)
	{
		if (cmd[*i_start] == '<' && cmd[*i_start - 1] != '<')
			input->last_infile_type[i_cmd] = INFILE;
		else if (cmd[*i_start] == '<' && cmd[*i_start - 1] == '<')
			input->last_infile_type[i_cmd] = HEREDOC;
	}
	if (input->last_outfile_type[i_cmd] == UNSET)
	{
		if (cmd[*i_start] == '>' && cmd[*i_start - 1] != '>')
			input->last_outfile_type[i_cmd] = OUTFILE;
		else if (cmd[*i_start] == '>' && cmd[*i_start - 1] == '>')
			input->last_outfile_type[i_cmd] = APP_OUTFILE;
	}
}

void	back_skip_quotes(char *str, int *i)
{
	char	c;

	c = str[*i];
	(*i)--;
	while (str[*i] != 0 && str[*i] != c)
		(*i)--;
}
