/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:58:42 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/07 15:23:37 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	env_parser(t_input *input)
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
	ft_free(input->cmd_line);
	input->cmd_line = buffer;
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
	ft_free(key);
}

void	fill_quotes(char *buffer, int *i, int *j, t_input *input)
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
