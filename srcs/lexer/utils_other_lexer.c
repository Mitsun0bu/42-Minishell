/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_other_lexer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:29:34 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/14 12:04:20 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/lexer.h"

int	bidim_tab_size(char **table)
{
	int	tab_size;
	int	i_tab;

	tab_size = 0;
	i_tab = -1;
	while (table[++i_tab])
		tab_size ++;
	return (tab_size);
}

int	skip_space(char *cmd, int *i)
{
	*i = *i + 1;
	if (cmd[*i] == '<' || cmd[*i] == '>')
		*i = *i + 1;
	while (is_space(cmd[*i]) == 1)
				*i = *i + 1;
	return (0);
}

int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}
