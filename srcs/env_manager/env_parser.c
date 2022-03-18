/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:58:42 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/18 13:42:00 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	env_parser(char *str, t_input *input)
{
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i])
			size += count_env(str, &i, 0, input);
		if (ft_strchr("\'\"", str[i]) && str[i])
			size += count_quotes(str, &i, input);
		if (!ft_strchr("$\'\"", str[i]) && str[i])
		{
			size++;
			i++;
		}
	}
	input->processed_line = ft_calloc(size + 1, sizeof(char));
	fill_buffer(str, input);
}

void	fill_buffer(char *str, t_input *input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i])
			fill_env(str, &i, &j, input);
		if (ft_strchr("\'\"", str[i]) && str[i])
			fill_quotes(str, &i, &j, input);
		if (!ft_strchr("$\'\"", str[i]) && str[i])
			input->processed_line[j++] = str[i++];
	}
}

void	fill_env(char *str, int *i, int *j, t_input *input)
{
	char	*key;
	char	*value;
	int		start;
	int		k;

	start = (*i) + 1;
	(*i)++;
	while (!ft_strchr("$<>=\'\"", str[*i])
		&& !is_isspace(str[*i]) && str[*i])
	{
		(*i)++;
	}
	key = ft_substr(str, start, *i - start);
	value = get_value(key, input);
	k = 0;
	if (value)
	{
		while (value[k])
		{
			input->processed_line[(*j)++] = value[k++];
		}
	}
	ft_free((void *)&key);
}

void	fill_quotes(char *str, int *i, int *j, t_input *input)
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
			fill_env(str, i, j, input);
			if (str[*i] == c)
			{
				break ;
			}
		}
		else
		{
			input->processed_line[(*j)++] = str[(*i)++];
		}
	}
	input->processed_line[(*j)++] = str[(*i)++];
}