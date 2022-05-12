/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_env_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:32:59 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/12 18:10:30 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	**convert_env_tab(t_input *input)
{
	char	**env_list;
	int		i;
	char	*env_str;

	env_list = ft_malloc(input, sizeof(char *), input->n_env + 1);
	input->gb->type = GARBAGE;
	env_list[input->n_env] = NULL;
	i = -1;
	while (++i < input->n_env)
	{
		env_str = ft_strjoin(input, input->env_tab[i].key, "=");
		input->gb->type = GARBAGE;
		env_str = ft_strjoin(input, env_str, input->env_tab[i].value);
		input->gb->type = GARBAGE;
		env_list[i] = env_str;
	}
	return (env_list);
}
