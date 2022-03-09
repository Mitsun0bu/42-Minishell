/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:51:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/09 16:26:09 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_exit(t_input *input)
{
	char	*value;
	int		level;

	value = ft_strdup(get_value("SHLVL", input));
	level = ft_atoi(value);
	if(level > input->start_shlvl)
	{
		value = ft_itoa(level - 1);
		change_value(input, "SHLVL", value);
		printf("exit\n");
		return (0);
	}
	else if (level == input->start_shlvl)
	{
		value = ft_itoa(level - 1);
		change_value(input, "SHLVL", value);
		printf("exit\n");
		exit(0);
	}
	exit(0);
}
