/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:51:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/24 16:45:26 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_exit(t_input *input)
{
	char	*value;
	int		level;

	value = get_value(input, "SHLVL");
	level = ft_atoi(value);
	if(level > input->start_shlvl)
	{
		value = ft_itoa(input, level - 1);
		input->garbage->type = ENV_STRUCT;
		change_value(input, "SHLVL", value);
		printf("exit\n");
		return (0);
	}
	else if (level == input->start_shlvl)
	{
		printf("exit\n");
		exit(0);
	}
	exit(0);
}
