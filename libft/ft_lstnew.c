/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:21:17 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/16 14:40:16 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}

/*
// === BEGINNING OF MY TEST ===

#include <stdio.h>

int	main()
{
	t_list	*list;
	char	*s;
	int		i;

	printf("\n=== TEST ft_lstnew WITH STRING ===\n\n");
	s = "test";
	list = ft_lstnew(s);
	printf("CONTENT : %s, NEXT : %p\n", (char *)list->content, list->next);
	free(list);

	printf("\n=== TEST ft_lstnew WITH INT ===\n\n");
	i = 42;
	list = ft_lstnew(&i);
	printf("CONTENT : %d, NEXT : %p\n", *(int *)list->content, list->next);
	free(list);
}

// === END OF MY TEST ===
*/
