/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_collector_utils_quotes.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:12:55 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/18 13:24:04 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	count_in_quotes(char *cmd, int *i, int *len, char c)
{
	(*len)++;
	(*i)++;
	if (cmd[*i] == c && !ft_strchr(" <>", cmd[*i + 2]))
		(*len)++;
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
	file[(*file_cursor)++] = cmd[(*cursor)++];
	if (cmd[*cursor] == c && !ft_strchr(" <>", cmd[*cursor + 2]))
		file[*file_cursor] = cmd[*cursor];
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
