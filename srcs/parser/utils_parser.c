/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 10:34:53 by agirardi          #+#    #+#             */
/*   Updated: 2022/04/14 13:07:06 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	check_red(int *red, char *cmd, int *i)
{
	*red = 0;
	if (ft_strchr("<>", cmd[*i]))
		*red = 1;
	if (ft_strchr("<>", cmd[*i]))
		while (ft_strchr("\t <>", cmd[*i + 1]))
			(*i)++;
}

int	end_check(char *cmd, int *i, int *red)
{
	if (ft_strchr("\t <>", cmd[*i + 1]) && *red == 0)
		return (0);
	(*i)++;
	return (1);
}
