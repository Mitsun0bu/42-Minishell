/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:11:19 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/04 18:56:13 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	find_unclosed_quotes(char *str);

int	check_quotes(t_input *input)
{
	if (find_unclosed_quotes(input->cmd_line) == YES)
		return (FAILED);
	return (SUCCESS);
}

static int	find_unclosed_quotes(char *str)
{
	int		i;
	int		quote_state;

	i = -1;
	quote_state = OUT;
	while (str[++i])
		if (ft_strchr("\"\'", str[i]))
			change_quote_state(&quote_state, str[i]);
	if (quote_state == IN)
	{
		print_err(258, NULL, "syntax error", "unclosed quote");
		return (YES);
	}
	return (NO);
}
