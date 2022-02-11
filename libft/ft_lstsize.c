/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:02:54 by llethuil          #+#    #+#             */
/*   Updated: 2021/11/11 17:08:08 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

/*
// === BEGINNING OF MY TEST ===

#include <stdio.h>

int	main()
{
	t_list	*list;
	int		i = 0;

	list = NULL;
	while (i < 10)
	{
		ft_lstadd_front(&list, ft_lstnew(&i));
		i ++;
	}
	printf("size of list = %d\n", ft_lstsize(list));
}

// === END OF MY TEST ===
*/
