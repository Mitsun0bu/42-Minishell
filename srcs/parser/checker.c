/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:18:59 by agirardi          #+#    #+#             */
/*   Updated: 2022/03/18 14:32:26 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_basics(t_input *input)
{
	int	i;

	i = -1;
	while (++i < input->n_cmd)
		if (!check_quotes(input->cmd_tab[i])
			|| !check_redirections(input->cmd_tab[i]))
			return (0);
	return (1);
}

int	check_quotes(char *str)
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
				printf("minishelled: syntax error unclosed quote\n");
				return (0);
			}
		}
	}
	return (1);
}

int	check_redirections(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_strchr("\"\'", str[i]))
			skip_quotes(str, &i);
		if (ft_strchr("<>", str[i]) && !str[i + 1])
			return (print_red_error_message(str, i, 0));
		if (ft_strchr("<>", str[i]))
		{
			if (ft_strchr("<>", str[i + 1]))
				if (str[i + 1] != str[i] || ft_strchr("<>", str[i + 2]))
					return (print_red_error_message(str, i, 1));
			if (!check_next_arg(str, i))
				return (0);
		}
	}
	return (1);
}

int	print_red_error_message(char *str, int i, int type)
{
	if (type == 0)
		printf("minishelled: syntax error near unexpected token `newline'\n");
	else
	{
		if (str[i] == '>')
			printf("bash: syntax error near unexpected token `<'\n");
		else
			printf("bash: syntax error near unexpected token `>'\n");
	}
	return (0);
}

int	check_pipe(t_input *input)
{
	char	last_letter;
	int		i;

	last_letter = 0;
	i = -1;
	while (input->cmd_line[++i])
	{
		while (is_isspace(input->cmd_line[i]) && input->cmd_line[i + 1])
			i++;
		if ((i == 0 && input->cmd_line[i] == '|')
			|| (input->cmd_line[i] == '|' && input->cmd_line[i + 1] == '|')
			|| (input->cmd_line[i] == '|' && last_letter == '|'))
		{
			printf("minishelled: syntax error near unexpected token `|'\n");
			return (0);
		}
		last_letter = input->cmd_line[i];
	}
	return (1);
}