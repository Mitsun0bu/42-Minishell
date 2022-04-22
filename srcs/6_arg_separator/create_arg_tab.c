/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arg_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:31:04 by agirardi          #+#    #+#             */
/*   Updated: 2022/04/22 10:11:00 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	fill_tab(char *cmd, char *exec_cmd, int i);
static void	copy_in_quote(char *cmd, char *exec_cmd, int *i, int *j);
static int	end_check(char *cmd, int *i, int *redir);
static void	check_red(int *redir, char *cmd, int *i);

int	create_arg_tab(t_input *input, int i)
{
	int	start;
	int	len;
	int	buff_start;
	int	j;

	start = -1;
	len = 0;
	j = -1;
	while (++j < get_number_of_arg(input->cmd_tab[i]))
	{
		buff_start = start;
		len = get_arg_len(input->cmd_tab[i], &start) + 1;
		input->cmd_exec_tab[i][j] = ft_calloc(input, sizeof(char), len);
		input->gb->type = INPUT_STRUCT;
		fill_tab(input->cmd_tab[i], input->cmd_exec_tab[i][j], buff_start);
	}
	return (1);
}

static void	fill_tab(char *cmd, char *exec_cmd, int i)
{
	int	redir;
	int	j;

	redir = 0;
	j = 0;
	while (cmd[++i])
	{
		while (!ft_strchr("\t\n\v\f\r <>", cmd[i]) && cmd[i])
		{
			if (ft_strchr("\"\'", cmd[i]))
			{
				if (redir == 1)
					skip_quotes(cmd, &i);
				else
					copy_in_quote(cmd, exec_cmd, &i, &j);
			}
			if (redir == 0 && !ft_strchr("\t\n\v\f\r <>", cmd[i]))
				exec_cmd[j++] = cmd[i];
			if (!end_check(cmd, &i, &redir))
				return ;
		}
		check_red(&redir, cmd, &i);
	}
}

static void	copy_in_quote(char *cmd, char *exec_cmd, int *i, int *j)
{
	char	c;

	c = cmd[*i];
	exec_cmd[(*j)++] = cmd[(*i)++];
	while (cmd[(*i)])
	{
		if (cmd[*i] == c)
		{
			exec_cmd[*j] = cmd[*i];
			break ;
		}
		exec_cmd[(*j)++] = cmd[(*i)++];
	}
}


static int	end_check(char *cmd, int *i, int *redir)
{
	if (ft_strchr("\t <>", cmd[*i + 1]) && *redir == 0)
		return (0);
	(*i)++;
	return (1);
}

static void	check_red(int *redir, char *cmd, int *i)
{
	*redir = 0;
	if (ft_strchr("<>", cmd[*i]))
		*redir = 1;
	if (ft_strchr("<>", cmd[*i]))
		while (ft_strchr("\t <>", cmd[*i + 1]))
			(*i)++;
}