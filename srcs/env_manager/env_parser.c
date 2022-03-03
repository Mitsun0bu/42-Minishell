/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:58:42 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/03 17:15:59 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	fill_quotes(char *buffer, int *i, int *j, t_input *input);

void	parse_env(t_input *input)
{
	char	*buffer;
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (input->cmd_line[i])
	{
		if (input->cmd_line[i] == '$' && input->cmd_line[i])
			size += count_env(input->cmd_line, &i, 0, input);
		if (ft_strchr("\'\"", input->cmd_line[i]) && input->cmd_line[i])
			size += count_quotes(input->cmd_line, &i, input);
		if (!ft_strchr("$\'\"", input->cmd_line[i]) && input->cmd_line[i])
		{
			size++;
			i++;
		}
	}
	buffer = ft_calloc(size + 1, sizeof(char));
	fill_buffer(buffer, input);
	free(input->cmd_line);
	input->cmd_line = buffer;
}

int	count_quotes(char *str, int *i, t_input *input)
{
	int		count;
	char	c;

	count = 0;
	c = str[*i];
	count++;
	(*i)++;
	while (str[*i] != c)
	{
		if (str[*i] == '$' && c == '\"')
		{
			count += count_env(str, i, 0, input);
			if (str[*i] == c)
				break ;
		}
		else
		{
			count++;
			(*i)++;
		}
	}
	count++;
	(*i)++;
	return (count);
}

void	fill_buffer(char *buffer, t_input *input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input->cmd_line[i])
	{
		if (input->cmd_line[i] == '$' && input->cmd_line[i])
			fill_env(buffer, &i, &j, input);
		if (ft_strchr("\'\"", input->cmd_line[i]) && input->cmd_line[i])
			fill_quotes(buffer, &i, &j, input);
		if (!ft_strchr("$\'\"", input->cmd_line[i]) && input->cmd_line[i])
			buffer[j++] = input->cmd_line[i++];
	}
}

void	fill_env(char *buffer, int *i, int *j, t_input *input)
{
	char	*key;
	char	*value;
	int		start;
	int		k;

	start = (*i) + 1;
	(*i)++;
	while (!ft_strchr("$<>=\'\"", input->cmd_line[*i])
		&& !is_isspace(input->cmd_line[*i]) && input->cmd_line[*i])
	{
		(*i)++;
	}
	key = ft_substr(input->cmd_line, start, *i - start);
	value = get_value(key, input);
	k = 0;
	if (value)
	{
		while (value[k])
		{
			buffer[(*j)++] = value[k++];
		}
	}
	free(key);
}

static void	fill_quotes(char *buffer, int *i, int *j, t_input *input)
{
	char	c;

	c = input->cmd_line[*i];
	buffer[*j] = input->cmd_line[*i];
	(*i)++;
	(*j)++;
	while (input->cmd_line[*i] != c && input->cmd_line[*i])
	{
		if (input->cmd_line[*i] == '$' && c == '\"')
		{
			fill_env(buffer, i, j, input);
			if (input->cmd_line[*i] == c)
			{
				break ;
			}
		}
		else
		{
			buffer[(*j)++] = input->cmd_line[(*i)++];
		}
	}
	buffer[(*j)++] = input->cmd_line[(*i)++];
}