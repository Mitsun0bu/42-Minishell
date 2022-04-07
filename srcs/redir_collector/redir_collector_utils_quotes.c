/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_collector_utils_quotes.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:12:55 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/07 16:07:55 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	count_in_quotes(char *cmd, int *i, int *len, char c)
{
	if (cmd[*i] == c && cmd[*i + 1] == c)
	{
		(*len) += 2;
		(*i) += 2;
		return (*len);
	}
	while (cmd[*i])
	{
		if (cmd[*i] == c)
		{
			if ((cmd[*i - 1] != c && !ft_strchr(" <>", cmd[*i - 1]))
				|| cmd[*i + 1] == c)
			{
				(*len)++;
				break ;
			}
		}
		(*len)++;
		(*i)++;
	}
	(*i)++;
	return (*len);
}

int	count_out_quotes(int *i, int *len)
{
	(*i)++;
	(*len)++;
	return (0);
}

int	copy_in_quotes(char *file, int *file_cursor, char *cmd, int *cursor)
{
	char	c;

	c = cmd[*cursor];
	if (cmd[*cursor] == c && cmd[(*cursor) + 1] == c)
	{
		file[(*file_cursor)++] = cmd[(*cursor)++];
		file[(*file_cursor)++] = cmd[(*cursor)++];
		return (0);
	}
	while (cmd[*cursor])
	{
		if (cmd[*cursor] == c)
		{
			if ((cmd[*cursor - 1] != c && !ft_strchr(" <>", cmd[*cursor - 1]))
				|| cmd[*cursor + 1] == c)
			{
				file[*file_cursor] = cmd[*cursor];
				break ;
			}
		}
		file[(*file_cursor)++] = cmd[(*cursor)++];
	}
	(*cursor)++;
	(*file_cursor)++;
	return (0);
}

int	copy_out_quotes(char *file, int *file_cursor, char *cmd, int *cursor)
{
	file[*file_cursor] = cmd[*cursor];
	(*file_cursor)++;
	(*cursor)++;
	return (0);
}
