/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env_var_processing.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:13:19 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/20 11:17:44 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	fill_value(t_input *input, char *value, int *i)
{
	int	j;

	j = 0;
	if (value)
		while (value[j])
			input->processed_line[(*i)++] = value[j++];
}

int	check_heredoc(char *str, int i)
{
	int	j;

	j = i - 1;
	while (j != 0 && is_space(str[j]))
		j--;
	if (j != 0 && str[j] == '<')
		if (j > 0 && str[j - 1] == '<')
			return (1);
	return (0);
}

char	*get_key_to_process(t_input *input, char *str, int *i)
{
	char	*key;
	int		start;

	if (str[(*i) + 1] == '?')
	{
		key = ft_strdup(input, "$?");
		(*i) += 2;
	}
	else if (is_space(str[(*i) + 1]) || ft_strchr("$<>", str[(*i) + 1]))
	{
		key = ft_strdup(input, "$");
		(*i)++;
	}
	else
	{
		start = ++(*i);
		while (!ft_strchr("$<>\'\"", str[*i]) && !is_space(str[*i]) && str[*i])
			(*i)++;
		key = ft_substr(input, str, start, *i - start);
	}
	input->gb->type = GARBAGE;
	return (key);
}
