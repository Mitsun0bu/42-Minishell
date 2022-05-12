/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env_var_in_quote.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:24:39 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/12 09:38:38 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char	*handle_single_quotes(t_input *input, char *s, int *i, char quote);
static char	*add_quotes(t_input *input, char *s, char quote);

char	*copy_env_var_in_quote(t_input *input, char *str, int *i, int red)
{
	char	*new_line;
	char	quote;

	new_line = ft_strdup(input, "");
	input->gb->type = GARBAGE;
	quote = str[(*i)++];
	while (str[*i] && str[*i] != quote)
	{
		if (str[*i] == '$' && quote == '\"')
		{
			new_line = ft_strjoin(input, new_line,
					convert_env_var(input, str, i, red));
			input->gb->type = GARBAGE;
		}
		else
		{
			new_line = ft_strjoin(input, new_line,
					handle_single_quotes(input, str, i, quote));
			input->gb->type = GARBAGE;
		}
	}
	new_line = add_quotes(input, new_line, quote);
	(*i)++;
	return (new_line);
}

static char	*handle_single_quotes(t_input *input, char *s, int *i, char quote)
{
	char	*new_line;
	int		start;

	start = *i;
	while (s[*i] && s[*i] != quote)
	{
		if (s[*i] == '$' && quote != '\'')
			break ;
		(*i)++;
	}
	new_line = ft_substr(input, s, start, (*i) - start);
	input->gb->type = GARBAGE;
	return (new_line);
}

static char	*add_quotes(t_input *input, char *s, char quote)
{
	char	*new_line;
	char	*quote_s;

	quote_s = ft_calloc(input, 2, sizeof(char));
	input->gb->type = GARBAGE;
	quote_s[0] = quote;
	new_line = ft_strjoin(input, quote_s, s);
	input->gb->type = GARBAGE;
	new_line = ft_strjoin(input, new_line, quote_s);
	input->gb->type = GARBAGE;
	return (new_line);
}
