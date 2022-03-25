/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_redir_type_tab.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:48:00 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/24 16:45:26 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	get_last_redir_type_tab(t_input *input)
{
	int	i_cmd;
	int	i_start;

	input->last_input_type_tab = ft_calloc(input, sizeof(int), input->n_cmd);
	input->garbage->type = INPUT_STRUCT;
	input->last_output_type_tab = ft_calloc(input, sizeof(int), input->n_cmd);
	input->garbage->type = INPUT_STRUCT;
	i_cmd = -1;
	while (++i_cmd < input->n_cmd)
	{
		i_start = ft_strlen(input->cmd_tab[i_cmd]);
		while (--i_start >= 0)
			get_last_types(input, input->cmd_tab[i_cmd], i_cmd, &i_start);
	}
}

void	get_last_types(t_input *input, char *cmd, int i_cmd, int *i_start)
{
	if (cmd[*i_start] == '\'' || cmd[*i_start] == '"')
		back_skip_quotes(cmd, i_start);
	if (!input->last_input_type_tab[i_cmd])
	{
		if (cmd[*i_start] == '<' && cmd[*i_start - 1] != '<')
			input->last_input_type_tab[i_cmd] = INPUT;
		else if (cmd[*i_start] == '<' && cmd[*i_start - 1] == '<')
			input->last_input_type_tab[i_cmd] = HEREDOC;
	}
	if (!input->last_output_type_tab[i_cmd])
	{
		if (cmd[*i_start] == '>' && cmd[*i_start - 1] != '>')
			input->last_output_type_tab[i_cmd] = TRUNC_OUTPUT;
		else if (cmd[*i_start] == '>' && cmd[*i_start - 1] == '>')
			input->last_output_type_tab[i_cmd] = APP_OUTPUT;
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