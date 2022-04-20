/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_g_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:39:06 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/20 17:39:21 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char *get_g_status(t_input *input)
{
	char *status;

	status = ft_itoa(input, g_status);
	input->gb->type = GARBAGE;

	return(status);
}