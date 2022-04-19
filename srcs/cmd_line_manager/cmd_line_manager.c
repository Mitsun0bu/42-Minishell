/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:33:25 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/19 16:19:55 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	cmd_line_manager(t_input *input)
{
	get_cmd_line(input);
	env_var_converter(input, input->cmd_line);
	input->cmd_line = ft_strdup(input, input->processed_line);
	input->gb->type = CMD_LINE;
}
