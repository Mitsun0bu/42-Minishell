/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_counter_redir_collector.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:16:10 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/16 14:18:14 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	count_any_redir(char *cmd, int type)
{
	int	n_red;
	int	i;

	n_red = 0;
	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == '\'' || cmd[i] == '"')
			skip_quotes(cmd, &i);
		if (type == 0 && (cmd[i] == '<' && cmd[i + 1] != '<'))
			if (i == 0 || (i != 0 && cmd[i - 1] != '<'))
				n_red ++;
		if (type == 1 && (cmd[i] == '>' && cmd[i + 1] != '>'))
			if (i == 0 || (i != 0 && cmd[i - 1] != '<'))
				n_red ++;
		if (type == 2 && (cmd[i] == '<' && cmd[i + 1] == '<'))
			if (i == 0 || (i != 0 && cmd[i - 1] != '<'))
				n_red ++;
		if (type == 3 && (cmd[i] == '>' && cmd[i + 1] == '>'))
			if (i == 0 || (i != 0 && cmd[i - 1] != '<'))
				n_red ++;
	}
	return (n_red);
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
		if (cmd[i] == '<' && cmd[i + 1] != '<')
		{
			if(i == 0 || (i != 0 && cmd[i - 1] != '<'))
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
	}
	return (0);
}

int	count_output_name_len(char *cmd, int *i_red)
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
		if (cmd[i] == '>' && cmd[i + 1] != '>')
		{
			if (i == 0 || (i != 0 && cmd[i - 1] != '>'))
			{
				skip_space(cmd, &i);
				while (cmd[i] && !ft_strchr(" \"\'<>", cmd[i]))
					count_out_quotes(&i, &len);
				if (cmd[i] == '\'' || cmd[i] == '"')
					count_in_quotes(cmd, &i, &len, cmd[i]);
				while (cmd[i] && !ft_strchr(" \"\'<>", cmd[i]))
					count_out_quotes(&i, &len);
				i --;
				return (len);
			}
		}
	}
	return (0);
}

int	count_delimiter_len(char *cmd, int *i_red)
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
		if (cmd[i] == '<' && cmd[i + 1] != '<')
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

int	count_app_output_name_len(char *cmd, int *i_red)
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
		if (cmd[i] == '>' && cmd[i + 1] != '>')
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