/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_garbage_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:03:37 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/06 19:03:51 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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