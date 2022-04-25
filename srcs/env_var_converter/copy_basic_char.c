/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_basic_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:25:09 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/25 16:25:16 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*copy_basic_char(t_input *input, char *str, int *i, int *red)
{
	char	*new_line;
	int		start;

	start = *i;
	while (str[*i] && !ft_strchr("$\'\"", str[*i]))
	{
		if (is_space(str[*i]) || ft_strchr("<>", str[*i]))
			*red = 0;
		(*i)++;
	}
	new_line = ft_substr(input, str, start, (*i) - start);
	return (new_line);
}