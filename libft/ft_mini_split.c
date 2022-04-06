/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:25:47 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/06 17:44:22 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../incs/main.h"

static int		ft_count_words(char *s, char c);
static int		ft_calloc_strs(t_input *input, char *s, char c, char **table);
static void		ft_fill_table(char *s, char c, char **table);

char	**ft_mini_split(t_input	*input, char *s, char c)
{
	int		words;
	char	**table;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	table = ft_calloc(input, sizeof(char *), words + 1);
	ft_calloc_strs(input, s, c, table);
	ft_fill_table(s, c, table);
	return (table);
}

static int	ft_count_words(char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (ft_strchr("\"\'", s[i]))
			skip_quotes(s, &i);
		if (s[i])
		{
			if (s[i] != c && s[i + 1] == c)
				word ++;
			else if (s[i] != c && s[i + 1] == '\0')
				word ++;
		}
		else
			return (1) ;
		i ++;
	}
	return (word);
}

static int	ft_calloc_strs(t_input *input, char *s, char c, char **table)
{
	int	i;
	int	quotes;
	int	i_table;
	int	j_table;

	i = 0;
	quotes = 0;
	i_table = -1;
	while (++i_table < ft_count_words(s, c))
	{
		j_table = 0;
		while (s[i])
		{
			if (s[i] == c && quotes == 0)
				break;
			if (ft_strchr("\"\'", s[i]) && quotes == 0)
				quotes = 1;
			j_table ++;
			i ++;
		}
		table[i_table] = ft_calloc(input, sizeof(char), j_table + 1);
		table[i_table][j_table] = '\0';
		i ++;
	}
	return (1);
}

static void	ft_fill_table(char *s, char c, char **table)
{
	int	i;
	int	quotes;
	int	i_table;
	int	j_table;

	i = 0;
	quotes = 0;
	i_table = -1;
	while (++i_table < ft_count_words(s, c))
	{
		j_table = 0;
		while (s[i])
		{
			if (ft_strchr("\"\'", s[i]) && quotes == 0)
				quotes = 1;
			else if (ft_strchr("\"\'", s[i]) && quotes == 1)
				quotes = 0;
			if (s[i] != c || (s[i] == c && quotes == 1))
				table[i_table][j_table++] = s[i++];
			else if (s[i++] == c && quotes == 0)
				break;
		}
	}
}
