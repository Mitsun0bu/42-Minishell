/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_last_output_redir_tab.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:48:00 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/16 11:04:15 by llethuil         ###   ########lyon.fr   */
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
		input->last_output_redir_tab[i_cmd] = find_output_type(input->cmd_tab[i_cmd], &i_start);
	}
	return (0);
}

int	find_output_type(char *str, int *i)
{
	while (*i >= 0)
	{
		if (str[*i] == '\'' || str[*i] == '"')
			back_skip_quotes(str, i);
		else if (str[*i] == '>' && str[*i - 1] != '>')
			return (TRUNC_OUTPUT);
		else if (str[*i] == '>' && str[*i - 1] == '>')
			return (APP_OUTPUT);
		(*i)--;
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
