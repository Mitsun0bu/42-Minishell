/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_env_var_in_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:36:44 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/20 11:29:40 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	convert_env_var_in_str(t_input *input, char *str)
{
	int		size;

	size = count_processed_line(input, str);
	input->processed_line = ft_calloc(input, sizeof(char), size + 1);
	input->gb->type = INPUT_STRUCT;
	fill_processed_line(input, str);
}

int	count_processed_line(t_input *input, char *str)
{
	int	size;
	int	redir;
	int	i;

	redir = 0;
	size = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i])
			size += count_env_var(input, str, &i, redir);
		if (ft_strchr("\'\"", str[i]) && str[i])
			size += count_quotes(input, str, &i, redir);
		if (str[i])
			size += count_basic(str, &redir, &i);
		if (check_heredoc(str, i))
			redir = HEREDOC;
	}
	return (size);
}

void	fill_processed_line(t_input *input, char *str)
{
	int	index[2];
	int	redir;

	redir = 0;
	index[0] = 0;
	index[1] = 0;
	while (str[index[0]])
	{
		if (str[index[0]] == '$' && str[index[0]])
			fill_env_var(input, str, index, redir);
		if (ft_strchr("\'\"", str[index[0]]) && str[index[0]])
			fill_quotes(input, str, index, redir);
		if (!ft_strchr("$\'\"", str[index[0]]) && str[index[0]])
			fill_basic(input, str, index, &redir);
		if (check_heredoc(str, index[0]))
			redir = HEREDOC;
	}
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

void	fill_basic(t_input *input, char *str, int index[], int *redir)
{
	while (str[index[0]] && !ft_strchr("$\'\"", str[index[0]]))
	{
		if (is_space(str[index[0]]) || ft_strchr("<>", str[index[0]]))
			*redir = 0;
		input->processed_line[index[1]++] = str[index[0]++];
	}
}

void	fill_env_var(t_input *input, char *str, int index[], int redir)
{
	char	*key;
	char	*value;

	if (str[index[0] + 1] == '?')
	{
		value = find_exit_status(input, str, index[0], redir);
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
		if (redir == 0)
			value = get_value_from_key(input, key);
		else
		{
			value = ft_strjoin(input, "$", key);
			input->gb->type = GARBAGE;
		}
	}
	fill_value(input, value, &index[1]);
}

char	*find_exit_status(t_input *input, char *str, int i, int redir)
{
	char	*value;

	if (redir == HEREDOC)
		value = ft_strdup(input, "$?");
	else if (is_first_command(str, i))
		return (get_status(input));
	else
		value = ft_strdup(input, "0");
	input->gb->type = GARBAGE;
	return (value);
}

void	fill_value(t_input *input, char *value, int *i)
{
	int	j;

	j = 0;
	if (value)
		while (value[j])
			input->processed_line[(*i)++] = value[j++];
}

void	fill_quotes(t_input *input, char *str, int index[], int redir)
{
	char	quote;

	quote = str[index[0]];
	input->processed_line[index[1]++] = str[index[0]++];
	while (str[index[0]] != quote && str[index[0]])
	{
		if (str[index[0]] == '$' && quote == '\"')
		{
			fill_env_var(input, str, index, redir);
			if (str[index[0]] == quote)
				break ;
		}
		else
			input->processed_line[index[1]++] = str[index[0]++];
	}
	input->processed_line[index[1]++] = str[index[0]++];
}