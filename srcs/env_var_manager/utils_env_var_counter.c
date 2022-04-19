/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env_var_counter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:58:45 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/19 19:16:05 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	count_env_var(t_input *input, char *str, int *i, int red)
{
	char	*key;
	int		key_len;
	int		count;
	int		j;

	key_len = 0;
	while (!ft_strchr("$<>\'\"", str[++ *i]) && !is_space(str[*i]) && str[*i])
		key_len++;
	key = ft_calloc(input, sizeof(char), key_len + 1);
	input->gb->type = GARBAGE;
	*i -= key_len + 1;
	j = -1;
	while (!ft_strchr("$<>\'\"", str[++ *i]) && !is_space(str[*i]) && str[*i])
		key[++j] = str[*i];
	count = ft_strlen(get_value_from_key(input, key));
	if (red == 0)
		return (count);
	return (0);
}

int	count_quotes(t_input *input, char *str, int *i)
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
			count += count_env_var(input, str, i, 0);
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
