/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env_counter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:58:45 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/07 11:32:12 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	count_env(char *str, int *i, int red, t_input *input)
{
	char	*key;
	int		key_len;
	int		count;
	int		j;

	key_len = 0;
	while (!ft_strchr("$<>\'\"", str[++ *i]) && !is_isspace(str[*i]) && str[*i])
		key_len++;
	key = ft_calloc(key_len + 1, sizeof(char));
	*i -= key_len + 1;
	j = -1;
	while (!ft_strchr("$<>\'\"", str[++ *i]) && !is_isspace(str[*i]) && str[*i])
		key[++j] = str[*i];
	count = ft_strlen(get_value(key, input));
	ft_free (key);
	if (red == 0)
		return (count);
	return (0);
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
