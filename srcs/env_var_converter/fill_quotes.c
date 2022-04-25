/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:24:39 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/25 17:06:38 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*fill_quotes(t_input *input, char *str, int *i, int red)
{
	char	*new_line;
	char	*buffer;
	char	quote;
	int		start;

	new_line = ft_calloc(input, 2, sizeof(char));
	input->gb->type = GARBAGE;

	quote = str[*i];
	new_line[0] = quote;
	(*i)++;
	while (str[*i] && str[*i] != quote)
	{
		if (str[*i] == '$' && quote == '\"')
		{
			new_line = ft_strjoin(input, new_line, convert_env_var(input, str, i, red));
			input->gb->type = GARBAGE;
		}
		else
		{
			start = *i;

			while (str[*i] && str[*i] != quote)
			{
				if (str[*i] == '$' && quote != '\'')
					break ;
				(*i)++;
			}
			buffer = ft_substr(input, str, start, (*i) - start + 1);
			input->gb->type = GARBAGE;
			new_line = ft_strjoin(input, new_line, buffer);
			input->gb->type = GARBAGE;
		}
	}
	(*i)++;

	return (new_line);
}