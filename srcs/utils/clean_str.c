/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:49:34 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/08 15:40:10 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*clean_str(t_input *input, char *str)
{
	int		len;
	char	*clean_str;

	len = 0;
	clean_str = NULL;
	len = get_clean_str_len(str);
	clean_str = fill_clean_str(input, str, len);
	return (clean_str);
}

int	get_clean_str_len(char *str)
{
	int		i;
	int		len;
	char	quote;

	i = -1;
	len = 0;
	quote = 0;
	while (str[++i])
	{
		if (ft_strchr("\'\"", str[i]))
		{
			quote = str[i];
			while(str[++i] && str[i] != quote)
				len ++;
			if (!str[++i])
				break ;
		}
		if (!ft_strchr("\'\"", str[i]))
			len ++;
	}
	return (len);
}

char	*fill_clean_str(t_input *input, char *str, int len)
{
	char	*clean_str;
	char	quote;
	int		i;
	int		j;

	clean_str = ft_calloc(input, sizeof(char), len + 1);
	input->garbage->type = CMD_LST;
	quote = 0;
	i = -1;
	j = -1;
	while (str[++i])
	{
		if (ft_strchr("\'\"", str[i]))
		{
			quote = str[i];
			while(str[++i] && str[i] != quote)
				clean_str[++j] = str[i];
			if (!str[++i])
				break ;
		}
		if (!ft_strchr("\'\"", str[i]))
			clean_str[++j] = str[i];
	}
	return (clean_str);
}