/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:36:34 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/11 15:37:01 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_pipe(t_input *input)
{
	int		i;
	int		quote_state;

	quote_state = 0;
	i = -1;
	while (input->cmd_line[++i])
	{
		while (is_space(input->cmd_line[i]) && input->cmd_line[i + 1])
			i++;
		if (i == 0 && input->cmd_line[i] == '|')
			return (FAILED);
		if (ft_strchr("\"\'", input->cmd_line[i]))
			change_quote_state(&quote_state);
		if (input->cmd_line[i] == '|' && quote_state == 0)
		{
			i ++;
			while (is_space(input->cmd_line[i]) && input->cmd_line[i + 1])
				i++;
			if (input->cmd_line[i] == '|')
				return (FAILED);
		}
	}
	return (1);
}

void	change_quote_state(int	*quote_state)
{
	if (*quote_state == 0)
		*quote_state = 1;
	else if (*quote_state == 1)
		*quote_state = 0;
	return ;
}