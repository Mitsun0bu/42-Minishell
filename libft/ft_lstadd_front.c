/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:52:09 by llethuil          #+#    #+#             */
/*   Updated: 2021/11/12 16:00:04 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
// === BEGINNING OF MY TEST ===

#include <stdio.h>

int	main()
{
	t_list	*node;
	int		i = 0;

	node = NULL;
	while (i < 10)
	{
		ft_lstadd_front(&node, ft_lstnew(&i));
		printf("==========================================================\n");
		printf("Iteration #%d\n", i);
		printf("The node is a pointer, containing the address : %p\n", node);
		printf("The structure content is %d\n", *(int *)node->content);
		if (i == 0)
			printf("The next address pointed by the struct : %p\n", node->next);
		else
			printf("The next address pointed by the struct : %p\n", node->next);

		printf("=======================================================\n\n\n");
		i ++;
	}
	free(node);
}

// === END OF MY TEST ===
*/
