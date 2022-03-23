/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env_finder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:11:10 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/23 13:58:03 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*find_key(t_input *input, char *str)
{
	char	*key;
	int		i;

	i = 0;
	while (str[i] != '=' && str[i])
		i++;
	key = ft_substr(input, str, 0, i);
	input->garbage->type = ENV_STRUCT;
	return (key);
}

char	*find_value(t_input *input, char *str)
{
	char	*value;
	int		key_count;
	int		i;

	key_count = 0;
	i = -1;
	while (str[++i] != '=' && str[i])
		key_count++;
	if (!str[i + 1])
		return (0);
	if (key_count == (int)ft_strlen(str))
		return (0);
	while (str[i])
		i++;
	value = ft_substr(input, str, key_count + 1, i);
	input->garbage->type = ENV_STRUCT;
	return (value);
}
