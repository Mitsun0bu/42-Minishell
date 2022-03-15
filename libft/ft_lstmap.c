/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:04:04 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/15 11:33:57 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*cmd;

	new = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		cmd = ft_lstnew((f)(lst->content));
		if (!cmd)
		{
			ft_lstclear(&new, (del));
			return (NULL);
		}
		ft_lstadd_back(&new, cmd);
		lst = lst->next;
	}
	return (new);
}
