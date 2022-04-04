/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:33:25 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/04 14:31:23 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	cmd_line_manager(t_input *input)
{
	get_cmd_line(input);
	env_converter(input, input->cmd_line);
	input->cmd_line = ft_strdup(input, input->processed_line);
	input->garbage->type = CMD_LINE;
	// ---------------- FINAL TEST ---------------- //
	printf("===================== CMD_LINE_MANAGER =====================\n");
	printf("cmd_line = %s\n", input->cmd_line);
	printf("============================================================\n");
	// -------------------------------------------- //
}
