/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:11:56 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/15 11:33:57 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*
// === BEGINNING OF MY TEST ===

#include <stdio.h>

int	main()
{
	t_list	*list;
	t_list	*tail;

	list = NULL;
	ft_lstadd_front(&list, ft_lstnew((int *)3));
	ft_lstadd_front(&list, ft_lstnew((int *)2));
	ft_lstadd_front(&list, ft_lstnew((int *)0));
	printf("content of first cmd =	%d\n", (int)list->content);
	tail = ft_lstlast(list);
	printf("content of last cmd =	%d\n", (int)tail->content);
}

// === END OF MY TEST ===
*/
