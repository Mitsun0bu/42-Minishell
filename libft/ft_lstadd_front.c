/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:52:09 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/15 11:33:57 by llethuil         ###   ########lyon.fr   */
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
	t_list	*cmd;
	int		i = 0;

	cmd = NULL;
	while (i < 10)
	{
		ft_lstadd_front(&cmd, ft_lstnew(&i));
		printf("==========================================================\n");
		printf("Iteration #%d\n", i);
		printf("The cmd is a pointer, containing the address : %p\n", cmd);
		printf("The structure content is %d\n", *(int *)cmd->content);
		if (i == 0)
			printf("The next address pointed by the struct : %p\n", cmd->next);
		else
			printf("The next address pointed by the struct : %p\n", cmd->next);

		printf("=======================================================\n\n\n");
		i ++;
	}
	free(cmd);
}

// === END OF MY TEST ===
*/
