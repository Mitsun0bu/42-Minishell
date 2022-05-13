/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:36:34 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/04 18:55:57 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_pipe(t_input *input)
{
	int		i;
	int		quote_state;

	quote_state = OUT;
	i = -1;
	while (++i < (int)ft_strlen(input->cmd_line))
	{
		while (is_space(input->cmd_line[i]) && input->cmd_line[i + 1])
			i++;
		if (i == 0 && input->cmd_line[i] == '|')
			return (FAILED);
		if (ft_strchr("\"\'", input->cmd_line[i]))
			change_quote_state(&quote_state, input->cmd_line[i]);
		if (input->cmd_line[i] == '|' && quote_state == OUT)
		{
			i ++;
			while (is_space(input->cmd_line[i]) && input->cmd_line[i + 1])
				i++;
			if (input->cmd_line[i] == '|')
				return (FAILED);
		}
	}
	return (SUCCESS);
}