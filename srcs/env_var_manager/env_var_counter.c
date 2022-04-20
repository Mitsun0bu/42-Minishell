/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:58:45 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/20 17:35:31 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	count_processed_line(t_input *input, char *str)
{
	int	size;
	int	red;
	int	i;

	red = 0;
	size = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i])
			size += count_env_var(input, str, &i, red);
		if (ft_strchr("\'\"", str[i]) && str[i])
			size += count_quotes(input, str, &i, red);
		if (str[i])
			size += count_basic(str, &red, &i);
		if (check_heredoc(str, i))
			red = HEREDOC;
	}
	return (size);
}

int	count_env_var(t_input *input, char *str, int *i, int red)
{
	char	*key;

	key = get_key_to_process(input, str, i);
	if (ft_strlen(key) == 1 && key[0] == '$')
		return (1);
	if (ft_strlen(key) == 2 && key[1] == '?')
	{
		if (red == HEREDOC)
			return (2);
		if (is_first_command(str, *i))
			return (ft_strlen(get_g_status(input)));
		return (1);
	}
	if (red == 0)
		return (ft_strlen(get_value_from_key(input, key)));
	if (red == HEREDOC)
		return (ft_strlen(key) + 1);
	return (0);
}

int	count_quotes(t_input *input, char *str, int *i, int red)
{
	int		count;
	char	quote;

	count = 2;
	quote = str[(*i)++];
	while (str[*i] && str[(*i)] != quote)
	{
		if (str[*i] == '$' && quote == '\"')
		{
			count += count_env_var(input, str, i, red);
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

int	count_basic(char *str, int *red, int *i)
{
	int	size;

	size = 0;
	while (str[*i] && !ft_strchr("$\'\"", str[*i]))
	{
		if (is_space(str[*i]) || ft_strchr("<>", str[*i]))
			*red = 0;
		(*i)++;
		size++;
	}
	return (size);
}
