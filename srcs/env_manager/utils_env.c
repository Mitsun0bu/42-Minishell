/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:43:38 by agirardi          #+#    #+#             */
/*   Updated: 2022/03/07 14:46:23 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*get_value(char *key, t_input *input)
{
	int	i;

	i = -1;
	while (++i < input->n_env)
	{
		if (ft_strncmp(key, input->env_tab[i].key, ft_strlen(key)) == 0)
			if (ft_strlen(key) == ft_strlen(input->env_tab[i].key))
				return (input->env_tab[i].value);
	}
	return (0);
}

int	search_key(const char *str, const char *key)
{
	int	i;

	if (ft_strlen(str) != ft_strlen(key))
		return (0);
	i = -1;
	while (key[++i])
	{
		if (key[i] != str[i])
			return (0);
	}
	return (1);
}

int	check_dubble(char *str, t_input *input)
{
	char	*key;
	int		check;
	int		i;

	check = 0;
	key = find_key(str);
	i = -1;
	while (++i < input->n_env)
	{
		if (ft_strncmp(key, input->env_tab[i].key, ft_strlen(key)) == 0)
			if (ft_strlen(key) == ft_strlen(input->env_tab[i].key))
				check = 1;
	}
	ft_free(key);
	if (check == 1)
		return (1);
	return (0);
}
