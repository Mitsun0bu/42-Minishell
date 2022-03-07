/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:23:59 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/07 11:28:47 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	cmd_lst_init(t_input *input, t_cmd_lst **lst_node)
{
	int	i;

	i = -1;
	while (++i < input->n_cmd)
		add_node_back(lst_node, create_new_node(&i, input));
	return (0);
}
