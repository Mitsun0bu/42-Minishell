/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_filename.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:17:18 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/21 17:07:27 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	copy_in_quote(char *file, int *f_cursor, char *cmd, int *cursor);
static int	copy_out_quote(char *file, int *f_cursor, char *cmd, int *cursor);

void	copy_filename(char *dest, char *cmd, int i_file, char c)
{
	static int	cursor = -1;
	int			f_cursor;

	if (i_file == 0)
		cursor = -1;
	f_cursor = 0;
	while (cmd[++cursor])
	{
		if ((cmd[cursor] == c && cmd[cursor + 1] != c && cmd[cursor - 1] != c)
			|| (cmd[cursor] == c && cmd[cursor + 1] == c))
		{
			skip_space_after_chev(cmd, &cursor);
			while (cmd[cursor] && !ft_strchr(" <>", cmd[cursor]))
			{
				if (cmd[cursor] == '\'' || cmd[cursor] == '"')
					copy_in_quote(dest, &f_cursor, cmd, &cursor);
				else
					copy_out_quote(dest, &f_cursor, cmd, &cursor);
			}
			return ;
		}
	}
}

static int	copy_in_quote(char *file, int *f_cursor, char *cmd, int *cursor)
{
	char	c;

	c = cmd[*cursor];
	if (cmd[*cursor] == c && cmd[(*cursor) + 1] == c)
	{
		file[(*f_cursor)++] = cmd[(*cursor)++];
		file[(*f_cursor)++] = cmd[(*cursor)++];
		return (0);
	}
	while (cmd[*cursor])
	{
		if (cmd[*cursor] == c)
		{
			if ((cmd[*cursor - 1] != c && !ft_strchr(" <>", cmd[*cursor - 1]))
				|| cmd[*cursor + 1] == c)
			{
				file[*f_cursor] = cmd[*cursor];
				break ;
			}
		}
		file[(*f_cursor)++] = cmd[(*cursor)++];
	}
	(*cursor)++;
	(*f_cursor)++;
	return (0);
}

static int	copy_out_quote(char *file, int *f_cursor, char *cmd, int *cursor)
{
	file[*f_cursor] = cmd[*cursor];
	(*f_cursor)++;
	(*cursor)++;
	return (0);
}
