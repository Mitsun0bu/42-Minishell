/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quotes_lexer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:35:00 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/14 12:04:19 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/lexer.h"

// int	skip_quotes(char *cmd, int *i, char c)
// {
// 	while (cmd[++ *i])
// 	{
// 		if (cmd[*i] == c)
// 		{
// 			*i = *i + 1;
// 			return (1);
// 		}
// 	}
// 	return (0);
// }

int	count_in_quotes(char *cmd, int *i, int *len, char c)
{
	*len = *len + 1;
	*i = *i + 1;
	if (cmd[*i] == c && !ft_strchr(" <>", cmd[*i + 2]))
		*len = *len + 1;
	while (cmd[*i])
	{
		if (cmd[*i] == c)
		{
			if ((cmd[*i - 1] != c && !ft_strchr(" <>", cmd[*i - 1]))
				|| cmd[*i + 1] == c)
			{
				*len = *len + 1;
				break ;
			}
		}
		*len = *len + 1;
		*i = *i + 1;
	}
	*i = *i + 1;
	return (*len);
}

int	cp_in_quotes(char *red, char *cmd, int *i, int *j)
{
	char	c;

	c = cmd[*i];
	red[(*j)++] = cmd[(*i)++];
	if (cmd[*i] == c && !ft_strchr(" <>", cmd[*i + 2]))
		red[*j] = cmd[*i];
	while (cmd[*i])
	{
		if (cmd[*i] == c)
		{
			if ((cmd[*i - 1] != c && !ft_strchr(" <>", cmd[*i - 1]))
				|| cmd[*i + 1] == c)
			{
				red[*j] = cmd[*i];
				break ;
			}
		}
		red[(*j)++] = cmd[(*i)++];
	}
	(*i)++;
	(*j)++;
	return (0);
}

int	count_out_quotes(int *i, int *len)
{
	*len = *len + 1;
	*i = *i + 1;
	return (0);
}

int	cp_out_quotes(char *red, char *cmd, int *i, int	*j)
{
	red[*j] = cmd[*i];
	*i = *i + 1;
	*j = *j + 1;
	return (0);
}
