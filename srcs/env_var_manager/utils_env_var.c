/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:43:38 by agirardi          #+#    #+#             */
/*   Updated: 2022/04/20 09:40:04 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*extract_key_from_str(t_input *input, char *str)
{
	char	*key;
	int		i;

	i = 0;
	while (str[i] != '=' && str[i])
		i++;
	key = ft_substr(input, str, 0, i);
	input->gb->type = ENV_STRUCT;
	return (key);
}

char	*extract_value_from_str(t_input *input, char *str)
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
	input->gb->type = ENV_STRUCT;
	return (value);
}

char	*get_value_from_key(t_input *input, char *key)
{
	int	i;

	i = -1;
	while (++i < input->n_env)
	{
		if (ft_strncmp(key, input->env_tab[i].key, ft_strlen(key)) == SUCCESS)
			if (ft_strlen(key) == ft_strlen(input->env_tab[i].key))
				return (input->env_tab[i].value);
	}
	return (0);
}

int	env_tab_contains_key(const char *str, const char *key)
{
	int	i;

	if (ft_strlen(str) != ft_strlen(key))
		return (0);
	i = -1;
	while (key[++i])
	{
		if (key[i] != str[i])
			return (NO);
	}
	return (YES);
}

int	find_existing_env_var(t_input *input, char *str)
{
	char	*key;
	int		i;

	key = extract_key_from_str(input, str);
	input->gb->type = GARBAGE;
	i = -1;
	while (++i < input->n_env)
	{
		if (ft_strncmp(key, input->env_tab[i].key, ft_strlen(key)) == 0)
			if (ft_strlen(key) == ft_strlen(input->env_tab[i].key))
				return (YES);
	}
	return (NO);
}
