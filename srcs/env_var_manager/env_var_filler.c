/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_filler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:08:53 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/20 17:36:13 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	fill_processed_line(t_input *input, char *str)
{
	int	index[2];
	int	red;

	red = 0;
	index[0] = 0;
	index[1] = 0;
	while (str[index[0]])
	{
		if (str[index[0]] == '$' && str[index[0]])
			fill_env_var(input, str, index, red);
		if (ft_strchr("\'\"", str[index[0]]) && str[index[0]])
			fill_quotes(input, str, index, red);
		if (!ft_strchr("$\'\"", str[index[0]]) && str[index[0]])
			fill_basic(input, str, index, &red);
		if (check_heredoc(str, index[0]))
			red = HEREDOC;
	}
}

void	fill_basic(t_input *input, char *str, int index[], int *red)
{
	while (str[index[0]] && !ft_strchr("$\'\"", str[index[0]]))
	{
		if (is_space(str[index[0]]) || ft_strchr("<>", str[index[0]]))
			*red = 0;
		input->processed_line[index[1]++] = str[index[0]++];
	}
}

void	fill_env_var(t_input *input, char *str, int index[], int red)
{
	char	*key;
	char	*value;

	if (str[index[0] + 1] == '?')
	{
		value = find_exit_status(input, str, index[0], red);
		index[0] += 2;
	}
	else if (is_space(str[index[0] + 1]) || ft_strchr("$<>", str[index[0] + 1]))
	{
		value = ft_strdup(input, "$");
		index[0] += 1;
	}
	else
	{
		key = get_key_to_process(input, str, &index[0]);
		if (red == 0)
			value = get_value_from_key(input, key);
		else
		{
			value = ft_strjoin(input, "$", key);
			input->gb->type = GARBAGE;
		}
	}
	fill_value(input, value, &index[1]);
}

void	fill_quotes(t_input *input, char *str, int index[], int red)
{
	char	quote;

	quote = str[index[0]];
	input->processed_line[index[1]++] = str[index[0]++];
	while (str[index[0]] != quote && str[index[0]])
	{
		if (str[index[0]] == '$' && quote == '\"')
		{
			fill_env_var(input, str, index, red);
			if (str[index[0]] == quote)
				break ;
		}
		else
			input->processed_line[index[1]++] = str[index[0]++];
	}
	input->processed_line[index[1]++] = str[index[0]++];
}
