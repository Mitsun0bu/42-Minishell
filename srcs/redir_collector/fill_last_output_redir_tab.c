/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_last_output_redir_tab.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:48:00 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/16 19:11:12 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	fill_last_output_redir_type_tab(t_input *input)
{
	int	i_cmd;
	int	i_start;

	input->last_output_redir_tab = safe_malloc(sizeof(int), input->n_cmd);
	i_cmd = -1;
	while (++i_cmd < input->n_cmd)
	{
		i_start = ft_strlen(input->cmd_tab[i_cmd]) - 1;
		while (--i_start >= 0)
		{
			if (input->cmd_tab[i_cmd][i_start] == '\''
				|| input->cmd_tab[i_cmd][i_start] == '"')
				back_skip_quotes(input->cmd_tab[i_cmd], &i_start);
			else if (input->cmd_tab[i_cmd][i_start] == '>'
				&& input->cmd_tab[i_cmd][i_start - 1] != '>')
				input->last_output_redir_tab[i_cmd] = TRUNC_OUTPUT;
			else if (input->cmd_tab[i_cmd][i_start] == '>'
				&& input->cmd_tab[i_cmd][i_start - 1] == '>')
				input->last_output_redir_tab[i_cmd] = APP_OUTPUT;
		}
		if (input->last_output_redir_tab[i_cmd] != TRUNC_OUTPUT
			&& input->last_output_redir_tab[i_cmd] != APP_OUTPUT)
			input->last_output_redir_tab[i_cmd] = 0;
	}
	return (0);
}

void	back_skip_quotes(char *str, int *i)
{
	char	c;

	c = str[*i];
	(*i)--;
	while (str[*i] != 0 && str[*i] != c)
		(*i)--;
}
