/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_collector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:36:30 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/20 10:08:14 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	redir_collector(t_input *input)
{
	int	i_cmd;
	int	type;
	int	i_file;

	get_last_redir_types_tab(input);
	malloc_cmd_dimension(input);
	malloc_types_dimension_for_each_cmd(input);
	i_cmd = -1;
	while (++i_cmd < input->n_cmd)
	{
		type = -1;
		while (++type < 4)
			malloc_n_file_dimension_for_each_type(input, i_cmd, type);
		type = -1;
		while (++type < 4)
		{
			i_file = -1;
			while (++i_file < count_n_file(input->cmd_tab[i_cmd], type))
			{
				malloc_name_for_each_file(input, i_cmd, type, i_file);
				copy_name_for_each_file(input, i_cmd, type, i_file);
			}
		}
	}
}
