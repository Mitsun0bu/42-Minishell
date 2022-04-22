/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_of_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:35:35 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/21 17:36:47 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	handle_quote(char *str, int *i, int *count, int *redir);

int	get_number_of_arg(char *str)
{
	int	redir;
	int	count;
	int	i;

	count = 0;
	redir = 0;
	i = -1;
	while (str[++i])
	{
		if (ft_strchr("\"\'", str[i]))
			handle_quote(str, &i, &count, &redir);
		if (ft_strchr("<>", str[i]))
			redir = 1;
		if ((!ft_strchr("\"\'<>", str[i]) && !is_space(str[i]))
			&& (i == 0 || ft_strchr(" <>", str[i - 1])))
		{
			if (redir == 1)
				redir = 0;
			else
				count++;
		}
	}
	return (count);
}

static void	handle_quote(char *str, int *i, int *count, int *redir)
{
	if ((*i > 0 && is_space(str[*i - 1])) || *i == 0)
		if (*redir == 0)
			*count = *count + 1;
	if (*redir == 1)
		*redir = 0;
	skip_quotes(str, i);
}