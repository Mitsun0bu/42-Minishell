/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:58:45 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/22 17:44:51 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	count_env_var(t_input *input, char *str, int *i, int redir)
{
	char	*key;

	key = get_key_to_process(input, str, i);
	if (ft_strlen(key) == 1 && key[0] == '$')
		return (1);
	if (ft_strlen(key) == 2 && key[1] == '?')
	{
		if (redir == HEREDOC)
			return (2);
		if (is_first_command(str, *i))
			return (ft_strlen(get_status(input)));
		return (1);
	}
	if (redir == 0)
		return (ft_strlen(get_value_from_key(input, key)));
	if (redir == HEREDOC)
		return (ft_strlen(key) + 1);
	return (0);
}

int	count_quotes(t_input *input, char *str, int *i, int redir)
{
	int		count;
	char	quote;

	count = 2;
	quote = str[(*i)++];
	while (str[*i] && str[(*i)] != quote)
	{
		if (str[*i] == '$' && quote == '\"')
		{
			count += count_env_var(input, str, i, redir);
			if (str[*i] == quote)
				break ;
		}
		else
		{
			(*i)++;
			count++;
		}
	}
	(*i)++;
	return (count);
}

int	count_basic(char *str, int *redir, int *i)
{
	int	size;

	size = 0;
	while (str[*i] && !ft_strchr("$\'\"", str[*i]))
	{
		if (is_space(str[*i]) || ft_strchr("<>", str[*i]))
			*redir = 0;
		(*i)++;
		size++;
	}
	return (size);
}
