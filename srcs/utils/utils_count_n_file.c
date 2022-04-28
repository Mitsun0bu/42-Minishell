/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_count_n_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:04:05 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/28 16:41:03 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
		{
			if (cmd[i + 1] == '<')
				i += 2;
			else
				n_red ++;
		}
		if (type == OUTFILE && cmd[i] == '>')
		{
			if (cmd[i + 1] == '>')
				i += 2;
			else
				n_red ++;
		}
		if (type == HEREDOC && cmd[i] == '<')
		{
			if (cmd[i + 1] == '<')
			{
				n_red ++;
				i += 2;
			}
		}
		if (type == APP_OUTFILE && cmd[i] == '>')
		{
			if (cmd[i + 1] == '>')
			{
				n_red ++;
				i += 2;
			}
		}
		i ++;
	}
	return (n_red);
}
