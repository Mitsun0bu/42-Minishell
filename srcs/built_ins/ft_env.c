/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:15:24 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/23 16:53:26 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "main.h"

int	ft_env(t_input *input)
{
	int	i;

	i = -1;
	while(++i < input->n_env)
	{
		if(input->env_tab[i].is_global == 1)
		{
			printf("%s=", input->env_tab[i].key);
			printf("%s\n", input->env_tab[i].value);
		}
		else
			i ++;
	}
	return (0);
}