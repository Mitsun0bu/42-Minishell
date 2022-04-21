/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_filename_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:04:12 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/21 17:08:21 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	count_in_quote(char *cmd, int *i, int *len, char c);
static int	count_out_quote(int *i, int *len);

int	count_filename_len(char *cmd, int i_file, char c)
{
	static int	cursor = -1;
	int			len;

	if (i_file == 0)
		cursor = -1;
	len = 0;
	while (cmd[++cursor])
	{
		if (cmd[cursor] == '\'' || cmd[cursor] == '"')
			skip_quotes(cmd, &cursor);
		if ((cmd[cursor] == c && cmd[cursor + 1] != c && cmd[cursor - 1] != c)
			|| (cmd[cursor] == c && cmd[cursor + 1] == c))
		{
			skip_space_after_chev(cmd, &cursor);
			while (cmd[cursor] && !ft_strchr(" <>", cmd[cursor]))
			{
				if (cmd[cursor] == '\'' || cmd[cursor] == '"')
					count_in_quote(cmd, &cursor, &len, cmd[cursor]);
				else
					count_out_quote(&cursor, &len);
			}
			return (len);
		}
	}
	return (0);
}

static int	count_in_quote(char *cmd, int *i, int *len, char c)
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

static int	count_out_quote(int *i, int *len)
{
	(*i)++;
	(*len)++;
	return (0);
}
