/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_split.'|'                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:25:47 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/12 15:54:12 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../incs/main.h"

static int		count_n_cmd(char *s);
static int		ft_calloc_cmd_name(t_input *input, char *s, char **table);
static void		ft_fill_table(char *s, char **table);

char	**ft_mini_split(t_input	*input, char *s)
{
	int		n_cmd;
	char	**table;

	if (!s)
		return (NULL);
	n_cmd = count_n_cmd(s);
	printf("n_cmd = %d\n", n_cmd);
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

static int	ft_calloc_cmd_name(t_input *input, char *s, char **table)
{
	int	i;
	int	quotes;
	int	i_table;
	int	j_table;

	i = 0;
	quotes = 0;
	i_table = -1;
	while (++i_table < count_n_cmd(s))
	{
		j_table = 0;
		while (s[i])
		{
			if (s[i] == '|' && quotes == 0)
				break ;
			if (ft_strchr("\"\'", s[i]) && quotes == 0)
				quotes = 1;
			if (s[i] != '|' || (s[i] == '|' && quotes == 1))
			{
				j_table ++;
				i ++;
			}
			else if (s[i++] == '|' && quotes == 0)
				break ;
		}
		table[i_table] = ft_calloc(input, sizeof(char), j_table + 1);
	}
	return (1);
}

static void	ft_fill_table(char *s, char **table)
{
	int	i;
	int	quotes;
	int	i_table;
	int	j_table;

	i = 0;
	quotes = 0;
	i_table = -1;
	while (++i_table < count_n_cmd(s))
	{
		j_table = 0;
		while (s[i])
		{
			if (ft_strchr("\"\'", s[i]) && quotes == 0)
				quotes = 1;
			else if (ft_strchr("\"\'", s[i]) && quotes == 1)
				quotes = 0;
			if (s[i] != '|' || (s[i] == '|' && quotes == 1))
				table[i_table][j_table++] = s[i++];
			else if (s[i++] == '|' && quotes == 0)
				break ;
		}
	}
}
