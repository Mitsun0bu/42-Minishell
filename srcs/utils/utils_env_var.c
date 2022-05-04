/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:43:38 by agirardi          #+#    #+#             */
/*   Updated: 2022/05/04 19:03:47 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*extract_key_from_str(t_input *input, char *str)
{
	char	*key;
	int		i;

	if (str[0] == '=')
		return ("=");
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
		if (ft_strcmp(key, input->env_tab[i].key) == SUCCESS)
			return (input->env_tab[i].value);
	return (0);
}

int	find_existing_env_var(t_input *input, char *str)
{
	char	*key;
	int		i;

	key = extract_key_from_str(input, str);
	i = -1;
	while (++i < input->n_env)
	{
		if (ft_strcmp(key, input->env_tab[i].key) == SUCCESS)
			return (YES);
	}
	return (NO);
}

void	add_to_env_tab(t_input *input, char *str, int type)
{
	t_env	*new_env_tab;
	int		i;

	input->n_env ++;
	new_env_tab = ft_malloc(input, sizeof(t_env), input->n_env);
	input->gb->type = ENV_STRUCT;
	i = -1;
	while (++i < input->n_env - 1)
	{
		new_env_tab[i].key = input->env_tab[i].key;
		new_env_tab[i].value = input->env_tab[i].value;
		new_env_tab[i].type = input->env_tab[i].type;
	}
	new_env_tab[i].key = extract_key_from_str(input, str);
	new_env_tab[i].value = extract_value_from_str(input, str);
	new_env_tab[i].type = type;
	input->env_tab = new_env_tab;
}

void	change_value(t_input *input, char *key, char *value)
{
	int	i;

	i = -1;
	while (++i < input->n_env)
	{
		if (ft_strcmp(key, input->env_tab[i].key) == SUCCESS)
		{
			input->env_tab[i].value = value;
			if (!value)
				input->env_tab[i].type = ENV_EMPTY;
			else
				input->env_tab[i].type = ENV;
		}
	}
}
