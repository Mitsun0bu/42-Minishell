/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:18:59 by agirardi          #+#    #+#             */
/*   Updated: 2022/02/14 12:08:12 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parser.h"
#include "../../incs/utils.h"

int	check_basics(t_input *input)
{
	int	i;

	i = -1;
	while (++i < input->n_cmd)
	{
		if (!input->cmd_tab[i][0])
			return (0);
		if (!check_quotes(input->cmd_tab[i]))
			return (0);
		if (!check_redirections(input->cmd_tab[i]))
			return (0);
	}
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
			if (str[i] == c)
				i++;
			else
				return (0);
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
			return (0);
		if (ft_strchr("<>", str[i]))
		{
			if (ft_strchr("<>", str[i + 1]))
			{
				if (str[i + 1] != str[i])
					return (0);
				if (ft_strchr("<>", str[i + 2]))
					return (0);
			}
			if (!check_next_arg(str, i))
				return (0);
		}
	}
	return (1);
}
