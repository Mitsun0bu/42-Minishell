/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:31:30 by agirardi          #+#    #+#             */
/*   Updated: 2022/04/21 18:21:13 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	count_in_quote(char *str, int *i, int *count, int red);

int	get_arg_len(char *str, int *i)
{
	int		count;
	int		red;

	red = 0;
	count = 0;
	while (str[++ *i])
	{
		while (!ft_strchr("\t\n\v\f\r <>", str[*i]) && str[*i])
		{
			if (ft_strchr("\"\'", str[*i]))
				count_in_quote(str, i, &count, red);
			if (red == 0)
				count++;
			if (ft_strchr("\t\n\v\f\r <>", str[*i + 1]) && red == 0)
				return (count);
			(*i)++;
		}
		red = 0;
		if (ft_strchr("<>", str[*i]))
			red = 1;
		if (ft_strchr("<>", str[*i]))
			while (ft_strchr("\t\n\v\f\r <>", str[*i + 1]))
				(*i)++;
	}
	return (count);
}

void	count_in_quote(char *str, int *i, int *count, int red)
{
	char	c;

	c = str[*i];
	if (red == 0)
		*count = *count + 1;
	while (str[++ *i] != c)
	{
		if (red == 0)
			*count = *count + 1;
	}
}




