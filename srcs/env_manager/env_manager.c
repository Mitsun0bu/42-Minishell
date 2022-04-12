/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:22:00 by agirardi          #+#    #+#             */
/*   Updated: 2022/04/12 15:39:44 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	add_to_env(t_input *input, char *str, int type)
{
	t_env	*new_env_tab;
	int		i;

	input->n_env += 1;
	new_env_tab = ft_malloc(input, sizeof(t_env), input->n_env);
	input->gb->type = ENV_STRUCT;
	i = -1;
	while (++i < input->n_env - 1)
	{
		new_env_tab[i].key = input->env_tab[i].key;
		new_env_tab[i].value = input->env_tab[i].value;
		new_env_tab[i].type = input->env_tab[i].type;
	}
	new_env_tab[i].key = find_key(input, str);
	new_env_tab[i].value = find_value(input, str);
	new_env_tab[i].type = type;
	input->env_tab = new_env_tab;
}

void	remove_from_env(t_input *input, char *key)
{
	t_env	*new_env_tab;
	int		i;
	int		j;

	input->n_env -= 1;
	new_env_tab = ft_malloc(input, sizeof(t_env), input->n_env);
	input->gb->type = ENV_STRUCT;
	i = -1;
	j = 0;
	while (++i < input->n_env + 1)
	{
		if (!search_key(input->env_tab[i].key, key))
		{
			new_env_tab[j].key = input->env_tab[i].key;
			new_env_tab[j].value = input->env_tab[i].value;
			new_env_tab[j].type = input->env_tab[i].type;
			j++;
		}
	}
	input->env_tab = new_env_tab;
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
				input->env_tab[i].value = value;
				if (!value)
					input->env_tab[i].type = ENV_EMPTY;
				else
					input->env_tab[i].type = ENV;
			}
		}
	}
}
