/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:36:44 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/20 11:29:40 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	env_var_converter(t_input *input, char *str)
{
	int		size;

	size = count_processed_line(input, str);
	input->processed_line = ft_calloc(input, sizeof(char), size + 1);
	input->gb->type = INPUT_STRUCT;
	fill_processed_line(input, str);
}
