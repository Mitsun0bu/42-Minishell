/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_new_garbage.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:47:32 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/28 14:31:05 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_garbage_lst	*ft_create_new_garbage(void *ptr)
{
	static int		i = 0;
	t_garbage_lst	*new_garbage;

	new_garbage = malloc(sizeof(t_garbage_lst));
	if (!new_garbage)
		return (NULL);
	new_garbage->index = i++;
	new_garbage->ptr = ptr;
	new_garbage->type = 0;
	new_garbage->next = NULL;
	new_garbage->previous = NULL;
	return (new_garbage);
}

