/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:15:51 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/16 11:16:16 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_is_space(t_input *input)
{
	int	i;

	i = 0;
	while (is_space(input->cmd_line[i]) == TRUE)
		i++;
	if (i == (int)ft_strlen(input->cmd_line))
		return (FAILED);
	return (SUCCESS);
}
