/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:58:42 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/14 12:46:40 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	env_var_converter(t_input *input, char *str)
{
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i])
			size += count_env_var(input, str, &i, 0);
		if (ft_strchr("\'\"", str[i]) && str[i])
			size += count_quotes(input, str, &i);
		if (!ft_strchr("$\'\"", str[i]) && str[i])
		{
			size++;
			i++;
		}
	}
	input->processed_line = ft_calloc(input, sizeof(char), size + 1);
	input->gb->type = INPUT_STRUCT;
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
			fill_env_var(input, str, &i, &j);
		if (ft_strchr("\'\"", str[i]) && str[i])
			fill_quotes(input, str, &i, &j);
		if (!ft_strchr("$\'\"", str[i]) && str[i])
			input->processed_line[j++] = str[i++];
	}
}

void	fill_env_var(t_input *input, char *str, int *i, int *j)
{
	char	*key;
	char	*value;
	int		start;
	int		k;

	start = (*i) + 1;
	(*i)++;
	while (!ft_strchr("$<>=\'\"", str[*i]) && !is_space(str[*i]) && str[*i])
		(*i)++;
	key = ft_substr(input, str, start, *i - start);
	input->gb->type = GARBAGE;
	value = get_value_from_key(input, key);
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
			fill_env_var(input, str, i, j);
			if (str[*i] == c)
				break ;
		}
		else
			input->processed_line[(*j)++] = str[(*i)++];
	}
	input->processed_line[(*j)++] = str[(*i)++];
}
