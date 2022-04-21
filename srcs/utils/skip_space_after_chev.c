/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_space_after_chev.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:43:10 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/21 18:28:37 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	skip_space_after_chev(char *cmd, int *i)
{
	(*i)++;
	if (cmd[*i] == '<' || cmd[*i] == '>')
		(*i)++;
	while (is_space(cmd[*i]) == YES)
		(*i)++;
}