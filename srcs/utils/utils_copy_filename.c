/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_copy_filename.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:17:18 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/29 11:16:53 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	copy_in_quote(char *file, int *i_dest, char *cmd, int *i);
static int	copy_out_quote(char *file, int *i_dest, char *cmd, int *i);

void	get_name(char *dest, int *i_dest, char *cmd, int *i)
{
	while (cmd[(*i)] && is_space(cmd[(*i)]) == YES)
		(*i) ++;
	while (cmd[(*i)] && !ft_strchr(" <>", cmd[(*i)]))
	{
		if (cmd[*i] == '\'' || cmd[*i] == '"')
			copy_in_quote(dest, i_dest, cmd, i);
		else
			copy_out_quote(dest, i_dest, cmd, i);
	}
	return ;
}

void	skip_other_redir(char *cmd, int *i)
{
	while (cmd[*i] && is_space(cmd[*i]) == YES)
		(*i) ++;
	while (cmd[*i] && !ft_strchr(" <>", cmd[*i]))
		(*i) ++;
	(*i) --;
}

static int	copy_in_quote(char *file, int *i_dest, char *cmd, int *i)
{
	char	c;

	c = cmd[*i];
	if (cmd[*i] == c && cmd[(*i) + 1] == c)
	{
		file[(*i_dest)++] = cmd[(*i)++];
		file[(*i_dest)++] = cmd[(*i)++];
		return (0);
	}
	while (cmd[*i])
	{
		if (cmd[*i] == c)
		{
			if ((cmd[*i - 1] != c && !ft_strchr(" <>", cmd[*i - 1]))
				|| cmd[*i + 1] == c)
			{
				file[*i_dest] = cmd[*i];
				break ;
			}
		}
		file[(*i_dest)++] = cmd[(*i)++];
	}
	(*i)++;
	(*i_dest)++;
	return (0);
}

static int	copy_out_quote(char *file, int *i_dest, char *cmd, int *i)
{
	file[*i_dest] = cmd[*i];
	(*i_dest)++;
	(*i)++;
	return (0);
}
