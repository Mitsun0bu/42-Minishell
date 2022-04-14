/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:22:00 by agirardi          #+#    #+#             */
/*   Updated: 2022/04/14 12:48:27 by llethuil         ###   ########lyon.fr   */
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
	new_env_tab[i].key = get_key_from_env_tab(input, str);
	new_env_tab[i].value = get_value_from_env_tab(input, str);
	new_env_tab[i].type = type;
	input->env_tab = new_env_tab;
}

void	remove_from_env(t_input *input, char *key_to_remove)
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
		if (find_key(input->env_tab[i].key, key_to_remove) == FAILED)
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
