/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:35:19 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/22 17:36:04 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	skip_quotes(char *str, int *i)
{
	char	c;

	c = str[*i];
	(*i)++;
	while (str[*i] && str[*i] != c)
		(*i)++;
}

void	back_skip_quotes(char *str, int *i)
{
	char	c;

	c = str[*i];
	(*i)--;
	while (str[*i] != 0 && str[*i] != c)
		(*i)--;
}

void	skip_space_after_chev(char *cmd, int *i)
{
	(*i)++;
	if (cmd[*i] == '<' || cmd[*i] == '>')
		(*i)++;
	while (is_space(cmd[*i]) == YES)
		(*i)++;
}


