/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:58:42 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/24 16:45:26 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	env_converter(t_input *input, char *str)
{
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i])
			size += count_env(input, str, &i, 0);
		if (ft_strchr("\'\"", str[i]) && str[i])
			size += count_quotes(input, str, &i);
		if (!ft_strchr("$\'\"", str[i]) && str[i])
		{
			size++;
			i++;
		}
	}
	input->processed_line = ft_calloc(input, sizeof(char), size + 1);
	input->garbage->type = INPUT_STRUCT;
	fill_buffer(input, str);
}

void	fill_buffer(t_input *input, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i])
			fill_env(input, str, &i, &j);
		if (ft_strchr("\'\"", str[i]) && str[i])
			fill_quotes(input, str, &i, &j);
		if (!ft_strchr("$\'\"", str[i]) && str[i])
			input->processed_line[j++] = str[i++];
	}
}

void	fill_env(t_input *input, char *str, int *i, int *j)
{
	char	*key;
	char	*value;
	int		start;
	int		k;

	start = (*i) + 1;
	(*i)++;
	while (!ft_strchr("$<>=\'\"", str[*i]) && !is_isspace(str[*i]) && str[*i])
		(*i)++;
	key = ft_substr(input, str, start, *i - start);
	input->garbage->type = GARBAGE;
	value = get_value(input, key);
	k = 0;
	if (value)
		while (value[k])
			input->processed_line[(*j)++] = value[k++];
}

void	fill_quotes(t_input *input, char *str, int *i, int *j)
{
	char	c;

	c = str[*i];
	input->processed_line[*j] = str[*i];
	(*i)++;
	(*j)++;
	while (str[*i] != c && str[*i])
	{
		if (str[*i] == '$' && c == '\"')
		{
			fill_env(input, str, i, j);
			if (str[*i] == c)
				break ;
		}
		else
			input->processed_line[(*j)++] = str[(*i)++];
	}
	input->processed_line[(*j)++] = str[(*i)++];
}
