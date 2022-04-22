/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_single_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:44:23 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/22 09:44:40 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	open_single_pipe(int *fd_tab)
{
	if (pipe(fd_tab) == -1)
	{
		print_err(1, NULL, "pipe()", "pipe opening failed");
		return (FAILED);
	}
	return (1);
}
