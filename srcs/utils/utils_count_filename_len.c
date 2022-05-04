/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_count_filename_len.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:04:12 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/04 19:03:19 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	count_in_quote(char *cmd, int *i, int *len, char c);
static int	count_out_quote(int *i, int *len);
static int	get_filename_len(char *cmd, int *i, int type);
static void	skip_filename_type(char *cmd, int *i, int type);

int	count_filename_len(char *cmd, int i_file, char c, int t)
{
	static int	i = 0;

	if (i_file == 0)
		i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'' || cmd[i] == '"')
			skip_quotes(cmd, &i);
		if (t == INFILE || t == OUTFILE)
		{
			if (cmd[i] == c && cmd[i + 1] != c && cmd[i - 1] != c)
				return (get_filename_len(cmd, &i, t));
			else if (cmd[i] == c && cmd[i + 1] == c)
				skip_filename_type(cmd, &i, t);
		}
		else if (t == HEREDOC || t == APP_OUTFILE)
		{
			if (cmd[i] == c && cmd[i + 1] == c)
				return (get_filename_len(cmd, &i, t));
			else if (cmd[i] == c && cmd[i + 1] != c && cmd[i - 1] != c)
				skip_filename_type(cmd, &i, t);
		}
		i ++;
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

static int	get_filename_len(char *cmd, int *i, int type)
{
	int	len;

	len = 0;
	if (type == INFILE || type == OUTFILE)
		(*i)++;
	else if (type == HEREDOC || type == APP_OUTFILE)
		(*i) += 2;
	while (cmd[(*i)] && is_space(cmd[(*i)]) == YES)
		(*i)++;
	while (cmd[(*i)] && !ft_strchr(" <>", cmd[(*i)]))
	{
		if (cmd[*i] == '\'' || cmd[*i] == '"')
			count_in_quote(cmd, i, &len, cmd[*i]);
		else
			count_out_quote(i, &len);
	}
	return (len);
}

static void	skip_filename_type(char *cmd, int *i, int type)
{
	if (type == INFILE || type == OUTFILE)
		(*i) += 2;
	else if (type == HEREDOC || type == APP_OUTFILE)
		(*i)++;
	while (cmd[*i] && is_space(cmd[*i]) == YES)
		(*i)++;
	while (cmd[*i] && !ft_strchr(" <>", cmd[*i]))
		(*i)++;
	(*i)--;
}
