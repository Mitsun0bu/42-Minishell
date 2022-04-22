/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_is_built_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:07:43 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/22 10:08:11 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	cmd_is_built_in(char *name)
{
	if (!name)
		return (0);
	else if (!ft_strncmp(name, "cd", 2) && !name[2])
		return (YES);
	else if (!ft_strncmp(name, "echo", 4) && !name[4])
		return (YES);
	else if (!ft_strncmp(name, "pwd", 3) && !name[3])
		return (YES);
	else if (!ft_strncmp(name, "env", 3) && !name[3])
		return (YES);
	else if (!ft_strncmp(name, "exit", 4) && !name[4])
		return (YES);
	else if (!ft_strncmp(name, "export", 6) && !name[6])
		return (YES);
	else if (!ft_strncmp(name, "unset", 5) && !name[5])
		return (YES);
	else
		return (NO);
}