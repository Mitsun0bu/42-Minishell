/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_count_n_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:04:05 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/12 11:35:17 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	handle_simple_red_file(char *cmd, int *i, int *n_red, char c);
static void	handle_double_red_file(char *cmd, int *i, int *n_red, char c);

int	count_n_file(char *cmd, int type)
{
	int	n_red;
	int	i;

	n_red = 0;
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'' || cmd[i] == '"')
			skip_quotes(cmd, &i);
		if (type == INFILE && cmd[i] == '<')
			handle_simple_red_file(cmd, &i, &n_red, '<');
		if (type == OUTFILE && cmd[i] == '>')
			handle_simple_red_file(cmd, &i, &n_red, '>');
		if (type == HEREDOC && cmd[i] == '<')
			handle_double_red_file(cmd, &i, &n_red, '<');
		if (type == APP_OUTFILE && cmd[i] == '>')
			handle_double_red_file(cmd, &i, &n_red, '>');
		i ++;
	}
	return (n_red);
}

static void	handle_simple_red_file(char *cmd, int *i, int *n_red, char c)
{
	if (cmd[*i + 1] == c)
		*i += 2;
	else
		(*n_red)++;
}

static void	handle_double_red_file(char *cmd, int *i, int *n_red, char c)
{
	if (cmd[*i + 1] == c)
	{
		(*n_red)++;
		*i += 2;
	}
}
