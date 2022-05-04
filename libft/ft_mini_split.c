/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:02:56 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/04 18:44:49 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../incs/main.h"

static int		count_n_cmd(char *s);
static int		ft_calloc_cmd_name(t_input *input, char *s, char **table);
static int		count_cmd_len(char *s, int *i);
static void		ft_fill_table(char *s, char **table);

char	**ft_mini_split(t_input	*input, char *s)
{
	int		n_cmd;
	char	**table;

	if (!s)
		return (NULL);
	n_cmd = count_n_cmd(s);
	table = ft_calloc(input, sizeof(char *), n_cmd + 1);
	ft_calloc_cmd_name(input, s, table);
	ft_fill_table(s, table);
	return (table);
}

static int	count_n_cmd(char *s)
{
	int	i;
	int	n_cmd;

	i = 0;
	n_cmd = 0;
	while (s[i])
	{
		if (ft_strchr("\"\'", s[i]))
			skip_quotes(s, &i);
		if (s[i])
		{
			if (s[i] != '|' && s[i + 1] == '|')
				n_cmd ++;
			else if (s[i] != '|' && s[i + 1] == '\0')
				n_cmd ++;
		}
		else
			return (1);
		i ++;
	}
	return (n_cmd);
}

static int	ft_calloc_cmd_name(t_input *input, char *str, char **table)
{
	int	len;
	int	i_str;
	int	i_table;

	len = 0;
	i_str = 0;
	i_table = -1;
	while (++i_table < count_n_cmd(str))
	{
		len = count_cmd_len(str, &i_str);
		table[i_table] = ft_calloc(input, sizeof(char), len + 1);
	}
	return (SUCCESS);
}

static int	count_cmd_len(char *s, int *i)
{
	int	len;
	int	quote_state;

	len = 0;
	quote_state = OUT;
	while (s[*i])
	{
		if (s[*i] == '|' && quote_state == OUT)
		{
			(*i)++;
			break ;
		}
		if (ft_strchr("\"\'", s[*i]))
			change_quote_state(&quote_state, s[*i]);
		if (s[*i] != '|' || (s[*i] == '|' && quote_state == IN))
		{
			len ++;
			(*i)++;
		}
		else
			(*i)++;
	}
	return (len);
}

static void	ft_fill_table(char *s, char **table)
{
	int	i;
	int	quote_state;
	int	i_table;
	int	j_table;

	i = 0;
	quote_state = 0;
	i_table = -1;
	while (++i_table < count_n_cmd(s))
	{
		j_table = 0;
		while (s[i])
		{
			if (s[i] == '|' && quote_state == OUT)
			{
				i++;
				break ;
			}
			if (ft_strchr("\"\'", s[i]))
				change_quote_state(&quote_state, s[i]);
			if (s[i] != '|' || (s[i] == '|' && quote_state == IN))
				table[i_table][j_table++] = s[i++];
			else
				i ++;
		}
	}
}
