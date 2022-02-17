/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:23:59 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/17 18:04:28 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "main.h"

int	cmd_lst_init(t_input *input, t_cmd_lst **lst_head)
{
	int	i;

	i = -1;
	while(++i < input->n_cmd)
		add_node_back(lst_head, create_new_node(&i, input));
	return (0);
}