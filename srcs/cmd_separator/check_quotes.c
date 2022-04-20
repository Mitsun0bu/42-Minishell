/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:11:19 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/20 14:13:08 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_quotes(t_input *input)
{
	int	i;

	i = -1;
	while (++i < input->n_cmd)
		if (find_unclosed_quotes(input->cmd_tab[i]) == YES)
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