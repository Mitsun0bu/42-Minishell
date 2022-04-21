/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_of_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:35:35 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/21 17:36:47 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	handle_quote(char *str, int *i, int *count, int *red);

int	get_number_of_arg(char *str)
{
	int	red;
	int	count;
	int	i;

	count = 0;
	red = 0;
	i = -1;
	while (str[++i])
	{
		if (ft_strchr("\"\'", str[i]))
			handle_quote(str, &i, &count, &red);
		if (ft_strchr("<>", str[i]))
			red = 1;
		if ((!ft_strchr("\"\'<>", str[i]) && !is_space(str[i]))
			&& (i == 0 || ft_strchr(" <>", str[i - 1])))
		{
			if (red == 1)
				red = 0;
			else
				count++;
		}
	}
	return (count);
}

static void	handle_quote(char *str, int *i, int *count, int *red)
{
	if ((*i > 0 && is_space(str[*i - 1])) || *i == 0)
		if (*red == 0)
			*count = *count + 1;
	if (*red == 1)
		*red = 0;
	skip_quotes(str, i);
}