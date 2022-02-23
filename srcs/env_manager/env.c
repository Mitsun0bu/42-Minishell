/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:22:00 by agirardi          #+#    #+#             */
/*   Updated: 2022/02/23 16:32:02 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_env(t_input *input, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	input->env_tab = safe_malloc(sizeof(t_env), i);
	input->n_env = i;
	i = -1;
	while (envp[++i])
	{
		input->env_tab[i].key = find_key(envp[i]);
		input->env_tab[i].value = find_value(envp[i]);
		input->env_tab[i].is_global = 1;
	}
}

void	add_to_env(t_input *input, char *str, int is_global)
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
		buffer[i].is_global = input->env_tab[i].is_global;
	}
	buffer[i].key = find_key(str);
	buffer[i].value = find_value(str);
	buffer[i].is_global = is_global;
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
			buffer[j].is_global = input->env_tab[i].is_global;
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

// check nom variable -> 1?\*"'

/* ========= DEBUG ========= */
//
// int h = -1;
// while (++h != input->n_env)
// {
// 	printf("%s=%s\n", input->env[h].key, input->env[h].value);
// }
//
