/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:23:59 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/15 15:27:28 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	cmd_lst_init(t_input *input, t_cmd_lst **cmd)
{
	int	i;

	i = -1;
	while (++i < input->n_cmd)
		add_cmd_back(cmd, create_new_cmd(&i, input));
	return (0);
}
