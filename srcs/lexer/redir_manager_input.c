/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_manager_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:27:25 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/15 16:13:37 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	malloc_input_redir_tab(t_input *input)
{
	int	i_cmd;
	int	n_red;

	i_cmd = -1;
	while (input->cmd_tab[++i_cmd])
	{
		n_red = count_input_redir(input->cmd_tab[i_cmd]);
		if (!n_red)
		{
			input->redir_tab[i_cmd][0] = malloc(2 * sizeof(char *));
			if (!input->redir_tab[i_cmd][0])
				return (1);
			input->redir_tab[i_cmd][0][0] = NULL;
		}
		else
		{
			input->redir_tab[i_cmd][0] = malloc((n_red + 1) * sizeof(char *));
			if (!input->redir_tab[i_cmd][0])
				return (1);
			input->redir_tab[i_cmd][0][n_red] = NULL;
		}
	}
	return (0);
}

int	count_input_redir(char *cmd)
{
	int	n_red;
	int	i;

	n_red = 0;
	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == '\'' || cmd[i] == '"')
			skip_quotes(cmd, &i);
		if (cmd[i] == '<' && cmd[i + 1] != '<' && cmd[i - 1] != '<')
			n_red ++;
	}
	return (n_red);
}

int	malloc_input_name(t_input *input, int *i_cmd)
{
	int	i_red;
	int	len;

	len = 0;
	i_red = -1;
	while (++i_red < count_input_redir(input->cmd_tab[*i_cmd]))
	{
		len = count_input_name_len(input->cmd_tab[*i_cmd], &i_red);
		input->redir_tab[*i_cmd][0][i_red] = malloc((len + 1) * sizeof(char));
		if (!input->redir_tab[*i_cmd][0][i_red])
			return (1);
		input->redir_tab[*i_cmd][0][i_red][len] = '\0';
	}
	return (0);
}

int	count_input_name_len(char *cmd, int	*i_red)
{
	static int	i = -1;
	int			len;

	if (*i_red == 0)
		i = -1;
	len = 0;
	while (cmd[++i])
	{
		if (cmd[i] == '\'' || cmd[i] == '"')
			skip_quotes(cmd, &i);
		if (cmd[i] == '<' && cmd[i + 1] != '<' && cmd[i - 1] != '<')
		{
			skip_space(cmd, &i);
			while (cmd[i] && !ft_strchr(" \"\'<>", cmd[i]))
				count_out_quotes(&i, &len);
			if (cmd[i] == '\'' || cmd[i] == '"')
				count_in_quotes(cmd, &i, &len, cmd[i]);
			while (cmd[i] && !ft_strchr(" <>", cmd[i]))
				count_out_quotes(&i, &len);
			i --;
			return (len);
		}
	}
	return (0);
}
