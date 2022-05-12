/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env_var_manip.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:43:38 by agirardi          #+#    #+#             */
/*   Updated: 2022/05/12 11:41:43 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
