/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_one_garbage_type.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:25:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/28 16:02:48 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_garbage_type(t_garbage_lst **garbage, int type)
{
	int				count;
	t_garbage_lst	*start;

	count = 0;
	start = *garbage;
	while (*garbage)
	{
		if ((*garbage)->type == type)
			count ++;
		*garbage = (*garbage)->next;
	}
	*garbage = start;
	return (count);
}

void ft_clear_one_garbage_type(t_garbage_lst **garbage, int type)
{
	t_garbage_lst	*temp;
	t_garbage_lst	*prev;

	temp = *garbage;
	if (temp && temp->type == type)
	{
		*garbage = temp->next;
		free(temp->ptr);
		free(temp);
		(*garbage)->previous = NULL;
		return;
	}
	while (temp && temp->type != type)
	{
		prev = temp;
		temp = temp->next;
	}
	if (!temp)
		return;
	prev->next = temp->next;
	free(temp->ptr);
	free(temp);
}