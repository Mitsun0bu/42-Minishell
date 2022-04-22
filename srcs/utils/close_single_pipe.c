/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_single_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:46:05 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/22 09:46:13 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	close_single_pipe(int *fd_tab)
{
	close(fd_tab[0]);
	close(fd_tab[1]);
}
