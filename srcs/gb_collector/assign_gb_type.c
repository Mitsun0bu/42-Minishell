/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_gb_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:03:37 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/06 19:03:51 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	assign_gb_type(t_input *input, char **table, int gb_type)
{
	int			i;
	int			j;
	t_gb_lst	*start;

	i = 0;
	j = -1;
	while (table[i])
		i ++;
	i ++;
	start = input->gb;
	while (++j < i)
	{
		input->gb->type = gb_type;
		input->gb = input->gb->next;
	}
	input->gb = start;
}
