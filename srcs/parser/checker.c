/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:18:59 by agirardi          #+#    #+#             */
/*   Updated: 2022/04/20 13:39:53 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_quotes_and_redir(t_input *input)
{
	int	i;

	i = -1;
	while (++i < input->n_cmd)
		if (find_unclosed_quotes(input->cmd_tab[i]) == YES
			/*|| find_invalid_redir(input->cmd_line) == YES*/)
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
				print_err(258, NULL, "syntax error", "unclosed quote");
				return (YES);
			}
		}
	}
	return (NO);
}

// int	find_invalid_redir(char *str)
// {
// 	int	i;

// 	i = -1;
// 	printf("0. str = %s\n", str);
// 	while (str[++i])
// 	{
// 		if (ft_strchr("\"\'", str[i]))
// 			skip_quotes(str, &i);
// 		if (ft_strchr("<>", str[i]))
// 		{
// 			if (check_redir_validity(str, i) == FAILED)
// 				return ();
// 			if (check_next_arg(str, i) == FAILED)
// 				return (YES);
// 		}
// 	}
// 	return (NO);
// }

// int	check_redir_validity(char *str, int i)
// {
// 	i ++;
// 	if (!str[i] || ft_strchr("<>", str[i]) && !str[i + 1])
// 	{
// 		invalid_redir(str, i, NEW_LINE);
// 		return (FAILED);
// 	}
// 	else if (ft_strchr("<>", str[i]))
// 	{
// 		i ++;
// 		while (is_space(str[i]) == YES)
// 			i ++;
// 		if (ft_strchr("<>", str[i]))
// 		{
// 			invalid_redir(str, i, REDIR);
// 			return (FAILED);
// 		}
// 	}
// 	else
// 		return (SUCCESS);
// }


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

// void	invalid_redir(char *str, int i, int type)
// {
// 	char	*message_1;
// 	char	*message_2;
// 	char	*message_3;
// 	char	*message_4;
// 	char	*message_5;

// 	message_1 = "syntax error near unexpected token `newline'";
// 	message_2 = "syntax error near unexpected token `>'";
// 	message_3 = "syntax error near unexpected token `>>'";
// 	message_4 = "syntax error near unexpected token `<'";
// 	message_5 = "syntax error near unexpected token `<<'";
// 	if (type == NEW_LINE)
// 		print_err(258, NULL, NULL, message_1);
// 	else if (type == REDIR)
// 	{
// 		if (str[i] == '>' && str[i + 1] != '>')
// 			print_err(258, NULL, NULL, message_2);
// 		else if (str[i] == '>' && str[i + 1] == '>')
// 			print_err(258, NULL, NULL, message_3);
// 		else if (str[i] == '<' && str[i + 1] != '<')
// 			print_err(258, NULL, NULL, message_4);
// 		else if (str[i] == '<' && str[i + 1] == '<')
// 			print_err(258, NULL, NULL, message_5);
// 	}
// }
