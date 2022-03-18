/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_collector_utils_other.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:12:39 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/18 11:12:44 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	(*i)++;
	if (cmd[*i] == '<' || cmd[*i] == '>')
		(*i)++;
	while (is_space(cmd[*i]) == 1)
				(*i)++;
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
