/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_env_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:32:59 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/22 16:00:30 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	count_env_var_to_convert(t_input *input);

char	**convert_env_tab(t_input *input)
{
	int		i_list;
	char	**env_list;
	int		i;
	char	*env_str;

	i_list = count_env_var_to_convert(input);
	env_list = ft_malloc(input, sizeof(char *), i_list + 1);
	input->gb->type = GARBAGE;
	env_list[i_list] = NULL;
	i = -1;
	while (++i < i_list)
	{
		if (input->env_tab[i].type == ENV
			|| input->env_tab[i].type == ENV_EMPTY)
		{
			env_str = ft_strjoin(input, input->env_tab[i].key, "=");
			input->gb->type = GARBAGE;
			env_str = ft_strjoin(input, env_str, input->env_tab[i].value);
			input->gb->type = GARBAGE;
			env_list[i] = ft_strdup(input, env_str);
			input->gb->type = GARBAGE;
		}
	}
	return (env_list);
}

static int	count_env_var_to_convert(t_input *input)
{
	int	i;
	int	i_list;

	i = -1;
	i_list = 0;
	while (++i < input->n_env)
		if (input->env_tab[i].type == ENV
			|| input->env_tab[i].type == ENV_EMPTY)
			i_list ++;
	return (i_list);
}
