/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_any_redir_in_redir_tab.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:52:08 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/16 14:56:04 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	write_any_redir_in_redir_tab(t_input *input, int type)
{
	int	i_cmd;
	int	n_red;
	int	i_red;

	i_cmd = -1;
	while (input->cmd_tab[++i_cmd])
	{
		n_red = count_any_redir(input->cmd_tab[i_cmd], type);
		if (!n_red && i_cmd == input->n_cmd - 1)
			return (0);
		if (!n_red && i_cmd != input->n_cmd - 1)
			i_cmd ++;
		i_red = -1;
		while (input->redir_tab[i_cmd][type][++i_red])
		{
			if (type == 0)
				cp_input_name(input, input->cmd_tab[i_cmd], &i_cmd, &i_red);
			if (type == 1)
				cp_output_name(input, input->cmd_tab[i_cmd], &i_cmd, &i_red);
			if (type == 2)
				cp_delimiter_name(input, input->cmd_tab[i_cmd], &i_cmd, &i_red);
			if (type == 3)
				cp_app_output_name(input, input->cmd_tab[i_cmd], &i_cmd, &i_red);
		}
	}
	return (0);
}

void	cp_input_name(t_input *input, char *cmd, int *i_cmd, int *i_red)
{
	static int	i = -1;
	int			j;

	if (*i_red == 0)
		i = -1;
	j = 0;
	while (cmd[++i])
	{
		if (cmd[i] == '\'' || cmd[i] == '"')
			skip_quotes(cmd, &i);
		if (cmd[i] == '<' && cmd[i + 1] != '<')
		{
			if (i == 0 || (i != 0 && cmd[i - 1] != '<'))
			{
				skip_space(cmd, &i);
				while (cmd[i] && !ft_strchr(" \"\'<>", cmd[i]))
					cp_out_quotes(input->redir_tab[*i_cmd][0][*i_red], cmd, &i, &j);
				if (cmd[i] == '\'' || cmd[i] == '"')
					cp_in_quotes(input->redir_tab[*i_cmd][0][*i_red], cmd, &i, &j);
				while (cmd[i] && !ft_strchr(" <>", cmd[i]))
					cp_out_quotes(input->redir_tab[*i_cmd][0][*i_red], cmd, &i, &j);
				i --;
				return ;
			}
		}
	}
}

void	cp_output_name(t_input *input, char *cmd, int *i_cmd, int *i_red)
{
	static int	i = -1;
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
			if (i == 0 || (i != 0 && cmd[i - 1] != '>'))
			{
				skip_space(cmd, &i);
				while (cmd[i] && !ft_strchr(" \"\'<>", cmd[i]))
					cp_out_quotes(input->redir_tab[*i_cmd][1][*i_red], cmd, &i, &j);
				if (cmd[i] == '\'' || cmd[i] == '"')
					cp_in_quotes(input->redir_tab[*i_cmd][1][*i_red], cmd, &i, &j);
				while (cmd[i] && !ft_strchr(" <>", cmd[i]))
					cp_out_quotes(input->redir_tab[*i_cmd][1][*i_red], cmd, &i, &j);
				i --;
				return ;
			}
		}
	}
}

void	cp_app_output_name(t_input *input, char *cmd, int *i_cmd, int *i_red)
{
	static int	i = -1;
	int			j;

	if (*i_red == 0)
		i = -1;
	j = 0;
	while (cmd[++i])
	{
		if (cmd[i] == '\'' || cmd[i] == '"')
			skip_quotes(cmd, &i);
		if (cmd[i] == '>' && cmd[i + 1] == '>')
		{
			skip_space(cmd, &i);
			while (cmd[i] && !ft_strchr(" \"\'<>", cmd[i]))
				cp_out_quotes(input->redir_tab[*i_cmd][3][*i_red], cmd, &i, &j);
			if (cmd[i] == '\'' || cmd[i] == '"')
				cp_in_quotes(input->redir_tab[*i_cmd][3][*i_red], cmd, &i, &j);
			while (cmd[i] && !ft_strchr(" <>", cmd[i]))
				cp_out_quotes(input->redir_tab[*i_cmd][3][*i_red], cmd, &i, &j);
			i --;
			return ;
		}
	}
}

void	cp_delimiter_name(t_input *input, char *cmd, int *i_cmd, int *i_red)
{
	static int	i = -1;
	int			j;

	if (*i_red == 0)
		i = -1;
	j = 0;
	while (cmd[++i])
	{
		if (cmd[i] == '\'' || cmd[i] == '"')
			skip_quotes(cmd, &i);
		if (cmd[i] == '<' && cmd[i + 1] == '<')
		{
			skip_space(cmd, &i);
			while (cmd[i] && !ft_strchr(" \"\'<>", cmd[i]))
				cp_out_quotes(input->redir_tab[*i_cmd][2][*i_red], cmd, &i, &j);
			if (cmd[i] == '\'' || cmd[i] == '"')
				cp_in_quotes(input->redir_tab[*i_cmd][2][*i_red], cmd, &i, &j);
			while (cmd[i] && !ft_strchr(" <>", cmd[i]))
				cp_out_quotes(input->redir_tab[*i_cmd][2][*i_red], cmd, &i, &j);
			i --;
			return ;
		}
	}
}