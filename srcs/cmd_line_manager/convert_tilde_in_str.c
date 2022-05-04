/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tilde_in_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:29:04 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/04 16:32:14 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char	*copy_char(t_input *input, char *str, int *i, int *red);
static int	identify_last_redir(char *line);
static char	*convert_tilde(t_input *input, char *str, int *i, int *red);
static char	*convert_tilde_not_after_heredoc(t_input *input, char *str, int *i);

char	*convert_tilde_in_str(t_input *input, char *str)
{
	char	*line;
	int		i;
	int		red;

	red = NO;
	i = 0;
	line = ft_strdup(input, "");
	input->gb->type = GARBAGE;
	while (str[i])
	{
		if (str[i] && str[i] != '~')
		{
			line = ft_strjoin(input, line, copy_char(input, str, &i, &red));
			input->gb->type = GARBAGE;
		}
		else if (str[i] == '~')
		{
			line = ft_strjoin(input, line, convert_tilde(input, str, &i, &red));
			input->gb->type = GARBAGE;
		}
		else
			i ++;
	}
	return (line);
}

static char	*copy_char(t_input *input, char *str, int *i, int *red)
{
	char	*line;
	int		start;
	int		quote_state;

	quote_state = OUT;
	start = *i;
	while (str[*i])
	{
		if (ft_strchr("\"\'", str[*i]))
			change_quote_state(&quote_state, str[*i]);
		if (ft_strchr("~", str[*i]) && quote_state == OUT)
			break ;
		(*i)++;
	}
	line = ft_substr(input, str, start, (*i) - start);
	*red = identify_last_redir(line);
	return (line);
}

static int	identify_last_redir(char *line)
{
	int	i;
	int	red;

	red = NO;
	i = ft_strlen(line) - 1;
	while (i >= 0)
	{
		if (ft_strchr("<>", line[i]))
		{
			if (line[i] == '<' && line[i - 1] == '<')
			{
				red = HEREDOC;
				i --;
			}
			else
				red = YES;
		}
		i --;
	}
	return (red);
}

static char	*convert_tilde(t_input *input, char *str, int *i, int *red)
{
	char	*value;

	value = ft_strdup(input, "");
	input->gb->type = GARBAGE;
	if (*red == NO || *red == YES)
		value = convert_tilde_not_after_heredoc(input, str, i);
	else
	{
		value = ft_strjoin(input, value, "~");
		input->gb->type = GARBAGE;
		(*i)++;
	}
	if (!value)
	{
		print_err(1, NULL, "cd", "HOME not set");
		return (NULL);
	}
	return (value);
}

static char	*convert_tilde_not_after_heredoc(t_input *input, char *str, int *i)
{
	char	*value;

	value = ft_strdup(input, "");
	if ((is_space(str[*i - 1]) == YES && *i != 0) && str[*i + 1] == '/')
		value = get_value_from_key(input, "HOME");
	else if ((is_space(str[*i - 1]) == NO && *i != 0)
		|| (is_space(str[*i + 1]) == NO && str[*i + 1] != '\0'))
	{
			value = ft_strjoin(input, value, "~");
			input->gb->type = GARBAGE;
	}
	else
		value = get_value_from_key(input, "HOME");
	(*i)++;
	return (value);
}
