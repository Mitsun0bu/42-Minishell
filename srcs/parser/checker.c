/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:18:59 by agirardi          #+#    #+#             */
/*   Updated: 2022/04/14 13:53:40 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_quotes_and_redir(t_input *input)
{
	int	i;

	i = -1;
	while (++i < input->n_cmd)
		if (find_unclosed_quotes(input->cmd_tab[i]) == YES
			|| find_invalid_redir(input->cmd_tab[i]) == YES)
			return (FAILED);
	return (1);
}

int	find_unclosed_quotes(char *str)
{
	char	c;
	int		i;

	i = -1;
	while (str[++i])
	{
		if (ft_strchr("\"\'", str[i]))
		{
			c = str[i];
			i++;
			while (str[i] != c && str[i])
				i++;
			if (!str[i])
			{
				print_error(NULL, "syntax error", "unclosed quote");
				return(YES);
			}
		}
	}
	return (NO);
}

int	find_invalid_redir(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_strchr("\"\'", str[i]))
			skip_quotes(str, &i);
		if (ft_strchr("<>", str[i]) && !str[i + 1])
			invalid_redir(str, i, NEW_LINE);
		if (ft_strchr("<>", str[i]))
		{
			if (ft_strchr("<>", str[i + 1]))
				if (str[i + 1] != str[i] || ft_strchr("<>", str[i + 2]))
					return (invalid_redir(str, i, REDIR));
			if (check_next_arg(str, i) == FAILED)
				return (YES);
		}
	}
	return (NO);
}

int	check_next_arg(char *str, int i)
{
	while (ft_strchr("<>", str[i]))
		i++;
	while (is_space(str[i]))
		i++;
	if (ft_strchr("<>", str[i]))
		return (FAILED);
	else
		return (SUCCESS);
}

int	invalid_redir(char *str, int i, int type)
{
	if (type == NEW_LINE)
		printf("minishelled: syntax error near unexpected token `newline'\n");
	else if (type == REDIR)
	{
		if (str[i] == '>')
			printf("minishelled: syntax error near unexpected token `<'\n");
		else
			printf("minishelled: syntax error near unexpected token `>'\n");
	}
	return (YES);
}
