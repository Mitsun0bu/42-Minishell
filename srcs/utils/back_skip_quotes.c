/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_skip_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:03:56 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/20 16:04:14 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	back_skip_quotes(char *str, int *i)
{
	char	c;

	c = str[*i];
	(*i)--;
	while (str[*i] != 0 && str[*i] != c)
		(*i)--;
}