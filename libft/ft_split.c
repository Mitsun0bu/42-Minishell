/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:25:47 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/24 16:45:26 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../incs/main.h"

static int		ft_count_words(char *s, char c);
static int		ft_calloc_strs(t_input *input, char *s, char c, char **table);
static void		ft_fill_table(char *s, char c, char **table);

char	**ft_split(t_input	*input, char *s, char c)
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
		if (s[i] != c && s[i + 1] == c)
			word ++;
		if (s[i] != c && s[i + 1] == '\0')
			word ++;
		i ++;
	}
	return (word);
}

static int	ft_calloc_strs(t_input *input, char *s, char c, char **table)
{
	int	i;
	int	i_table;
	int	j_table;

	i = 0;
	i_table = 0;
	while (s[i] && i_table < ft_count_words(s, c))
	{
		while (s[i] == c)
			i ++;
		j_table = 0;
		while (s[i] != c && s[i + 1] != '\0')
		{
			j_table ++;
			i ++;
		}
		if (s[i] != c && s[i + 1] == '\0')
			j_table ++;
		table[i_table] = ft_calloc(input, sizeof(char), j_table + 1);
		input->garbage->type = INPUT_STRUCT;
		i_table ++;
		i ++;
	}
	return (1);
}

static void	ft_fill_table(char *s, char c, char **table)
{
	int	i;
	int	i_table;
	int	j_table;

	i = 0;
	i_table = 0;
	while (s[i] && i_table < ft_count_words(s, c))
	{
		j_table = 0;
		while (s[i] == c)
			i ++;
		while (s[i] != c && s[i + 1] != '\0')
			table[i_table][j_table++] = s[i++];
		if (s[i] != c && s[i + 1] == '\0')
			table[i_table][j_table++] = s[i];
		table[i_table][j_table] = '\0';
		i_table ++;
		i ++;
	}
}
