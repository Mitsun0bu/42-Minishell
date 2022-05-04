/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:31:30 by agirardi          #+#    #+#             */
/*   Updated: 2022/05/04 18:52:31 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	count_in_quote(char *str, int *i, int *count, int redir);

int	get_arg_len(char *str, int *i)
{
	int		count;
	int		redir;

	redir = 0;
	count = 0;
	while (str[++ *i])
	{
		while (!ft_strchr("\t\n\v\f\r <>", str[*i]) && str[*i])
		{
			if (ft_strchr("\"\'", str[*i]))
				count_in_quote(str, i, &count, redir);
			if (redir == 0)
				count++;
			if (ft_strchr("\t\n\v\f\r <>", str[*i + 1]) && redir == 0)
				return (count);
			(*i)++;
		}
		redir = 0;
		if (ft_strchr("<>", str[*i]))
			redir = 1;
		if (ft_strchr("<>", str[*i]))
			while (ft_strchr("\t\n\v\f\r <>", str[*i + 1]))
				(*i)++;
	}
	return (count);
}

void	count_in_quote(char *str, int *i, int *count, int redir)
{
	char	c;

	c = str[*i];
	if (redir == 0)
		*count = *count + 1;
	while (str[++ *i] != c)
	{
		if (redir == 0)
			*count = *count + 1;
	}
}
