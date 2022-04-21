/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_n_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:04:05 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/21 16:04:39 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	count_n_file(char *cmd, int type)
{
	int	n_red;
	int	i;

	n_red = 0;
	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == '\'' || cmd[i] == '"')
			skip_quotes(cmd, &i);
		if (type == INFILE)
			if (cmd[i] == '<' && cmd[i + 1] != '<' && cmd[i - 1] != '<')
				n_red ++;
		if (type == OUTFILE)
			if (cmd[i] == '>' && cmd[i + 1] != '>' && cmd[i - 1] != '>')
				n_red ++;
		if (type == HEREDOC)
			if (cmd[i] == '<' && cmd[i + 1] == '<')
					n_red ++;
		if (type == APP_OUTFILE)
			if (cmd[i] == '>' && cmd[i + 1] == '>')
					n_red ++;
	}
	return (n_red);
}
