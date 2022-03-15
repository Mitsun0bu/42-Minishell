/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:53:18 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/15 11:33:57 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_cmd;

	if (!*lst)
		*lst = new;
	else
	{
		last_cmd = ft_lstlast(*lst);
		last_cmd->next = new;
	}
}

/*
// === BEGINNING OF MY TEST ===

#include <stdio.h>

int	main()
{
	t_list	*list;
	t_list	*tail;

	list = NULL;
	ft_lstadd_back(&list, ft_lstnew((int *)0));
	ft_lstadd_back(&list, ft_lstnew((int *)1));
	ft_lstadd_back(&list, ft_lstnew((int *)3));
	printf("content of first cmd =	%d\n", (int)list->content);
	tail = ft_lstlast(list);
	printf("content of last cmd =	%d\n", (int)tail->content);
}

// === END OF MY TEST ===
*/
