/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_redir_tab_app_output.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:52:08 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/10 11:06:57 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/lexer.h"

int	fill_redir_tab_app_output(t_input *input)
{
	int	i_cmd;
	int	n_red;
	int	i_red;

	i_cmd = -1;
	while (input->cmd_tab[++i_cmd])
	{
		n_red = count_app_output_redir(input->cmd_tab[i_cmd]);
		if (!n_red && i_cmd == input->n_cmd - 1)
			return (0);
		if (!n_red && i_cmd != input->n_cmd - 1)
			i_cmd ++;
		i_red = -1;
		while (input->redir_tab[i_cmd][3][++i_red])
			cp_app_output_name(input, input->cmd_tab[i_cmd], &i_cmd, &i_red);
	}
	return (0);
}

int	cp_app_output_name(t_input *input, char *cmd, int *i_cmd, int *i_red)
{
	static int	i;
	int			j;

	if (*i_red == 0)
		i = -1;
	j = 0;
	while (cmd[++i])
	{
		if (cmd[i] == '\'' || cmd[i] == '"')
			skip_quotes(cmd, &i);
		if (cmd[i] == '>' && cmd[i + 1] != '>')
		{
			skip_space(cmd, &i);
			while (cmd[i] && !ft_strchr(" \"\'<>", cmd[i]))
				cp_out_quotes(input->redir_tab[*i_cmd][3][*i_red], cmd, &i, &j);
			if (cmd[i] == '\'' || cmd[i] == '"')
				cp_in_quotes(input->redir_tab[*i_cmd][3][*i_red], cmd, &i, &j);
			while (cmd[i] && !ft_strchr(" <>", cmd[i]))
				cp_out_quotes(input->redir_tab[*i_cmd][3][*i_red], cmd, &i, &j);
			i --;
			return (0);
		}
	}
	return (0);
}
