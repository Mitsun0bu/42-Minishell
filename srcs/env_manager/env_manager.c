/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:22:00 by agirardi          #+#    #+#             */
/*   Updated: 2022/03/10 11:07:30 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	add_to_env(t_input *input, char *str, int type)
{
	t_env	*buffer;
	int		i;

	input->n_env += 1;
	buffer = safe_malloc(sizeof(t_env), input->n_env);
	i = -1;
	while (++i < input->n_env - 1)
	{
		buffer[i].key = input->env_tab[i].key;
		buffer[i].value = input->env_tab[i].value;
		buffer[i].type = input->env_tab[i].type;
	}
	buffer[i].key = find_key(str);
	buffer[i].value = find_value(str);
	buffer[i].type = type;
	ft_free(input->env_tab);
	input->env_tab = buffer;
}

void	remove_from_env(t_input *input, char *key)
{
	t_env	*buffer;
	int		i;
	int		j;

	input->n_env -= 1;
	buffer = safe_malloc(sizeof(t_env), input->n_env);
	i = -1;
	j = 0;
	while (++i < input->n_env + 1)
	{
		if (!search_key(input->env_tab[i].key, key))
		{
			buffer[j].key = input->env_tab[i].key;
			buffer[j].value = input->env_tab[i].value;
			buffer[j].type = input->env_tab[i].type;
			j++;
		}
		else
		{
			ft_free (input->env_tab[i].key);
			ft_free (input->env_tab[i].value);
		}
	}
	ft_free(input->env_tab);
	input->env_tab = buffer;
}

void	change_value(t_input *input, char *key, char *value)
{
	int	i;

	i = -1;
	while (++i < input->n_env)
	{
		if (ft_strncmp(key, input->env_tab[i].key, ft_strlen(key)) == 0)
		{
			if (ft_strlen(key) == ft_strlen(input->env_tab[i].key))
			{
				ft_free(input->env_tab[i].value);
				input->env_tab[i].value = value;
				if (!value)
					input->env_tab[i].type = EXPORT_EMPTY;
				else
					input->env_tab[i].type = ENV;
			}
		}
	}
}
