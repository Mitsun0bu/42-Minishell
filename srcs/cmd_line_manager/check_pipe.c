/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:36:34 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/16 14:33:02 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	find_pipe_error(t_input *input, int *i, int *quote_state);

int	check_pipe(t_input *input)
{
	int		start;
	int		quote_state;
	int		i;

	start = 0;
	quote_state = OUT;
	i = -1;
	while (is_space(input->cmd_line[++i]))
		start ++;
	while (i < (int)ft_strlen(input->cmd_line))
	{
		if (input->cmd_line[start] == '|')
			return (FAILED);
		if (ft_strchr("\"\'", input->cmd_line[i]))
			change_quote_state(&quote_state, input->cmd_line[i]);
		if (find_pipe_error(input, &i, &quote_state) == YES)
			return (FAILED);
		i ++;
	}
	return (SUCCESS);
}

static int	find_pipe_error(t_input *input, int *i, int *quote_state)
{
	int	invalid_red;

	invalid_red = NO;
	if (input->cmd_line[*i] == '|' && *quote_state == OUT)
	{
		if (*i != 0)
			(*i)--;
		while (*i != 0 && is_space(input->cmd_line[*i]))
			(*i)--;
		if (ft_strchr("><", input->cmd_line[*i]))
			invalid_red = YES;
		(*i)++;
		while (is_space(input->cmd_line[*i]))
			(*i)++;
		(*i)++;
		while (is_space(input->cmd_line[*i]) && input->cmd_line[*i + 1])
			(*i)++;
		if (input->cmd_line[*i] == '|' || invalid_red == YES)
			return (YES);
	}
	return (NO);
}
