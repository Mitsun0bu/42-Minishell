/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:33:25 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/23 16:22:21 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	cmd_line_manager(t_input *input)
{
	get_cmd_line(input);
	env_converter(input, input->cmd_line);
	input->cmd_line = ft_strdup(input, input->processed_line);
	input->garbage->type = INPUT_STRUCT;
	return ;
}
