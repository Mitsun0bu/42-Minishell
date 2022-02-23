/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:43:38 by agirardi          #+#    #+#             */
/*   Updated: 2022/02/23 16:35:53 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*find_key(char *str)
{
	char	*key;
	int		i;

	i = 0;
	while (str[i] != '=')
		i++;
	key = ft_substr(str, 0, i);
	return (key);
}

char	*find_value(char *str)
{
	char	*value;
	int		key_count;
	int		i;

	key_count = 0;
	i = -1;
	while (str[++i] != '=')
		key_count++;
	while (str[i])
		i++;
	value = ft_substr(str, key_count + 1, i);
	return (value);
}

int	count_env(char *str, int *i, int red, t_input *input)
{
	char	*key;
	int		key_len;
	int		count;
	int		j;

	key_len = 0;
	while (!ft_strchr("$<>\'\"", str[++ *i]) && !is_isspace(str[*i]) && str[*i])
		key_len++;
	key = ft_calloc(key_len + 1, sizeof(char));
	*i -= key_len + 1;
	j = -1;
	while (!ft_strchr("$<>\'\"", str[++ *i]) && !is_isspace(str[*i]) && str[*i])
		key[++j] = str[*i];
	count = ft_strlen(get_value(key, input));
	ft_free (key);
	if (red == 0)
		return (count);
	return (0);
	// ajouter un return a get_value s'il ne trouve pas
}
// use ft_substr

char	*get_value(char *str, t_input *input)
{
	int	i;

	i = -1;
	while (++i < input->n_env)
	{
		if (ft_strncmp(str, input->env_tab[i].key, ft_strlen(str)) == 0)
			if (ft_strlen(str) == ft_strlen(input->env_tab[i].key))
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

void	free_env(t_input *input)
{
	int	i;

	i = -1;
	while (++i < input->n_env)
	{
		ft_free(input->env_tab[i].key);
		ft_free(input->env_tab[i].value);
	}
	ft_free(input->env_tab);
}
