/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:12:43 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/05 16:15:34 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	is_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

void	skip_quotes(char *str, int *i)
{
	char	c;

	c = str[*i];
	(*i)++;
	while (str[*i] && str[*i] != c)
		(*i)++;
}

void	ft_free(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

void	assign_garbage_type(t_input *input, char **table, int garbage_type)
{
	int	i;
	int	j;
	t_garbage_lst	*start;

	i = 0;
	j = -1;
	while (table[i])
		i ++;
	i ++;
	start = input->garbage;
	while(++j < i)
	{
		input->garbage->type = garbage_type;
		input->garbage = input->garbage->next;
	}
	input->garbage = start;
}

