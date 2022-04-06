/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:37:12 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/06 19:09:44 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	split_cmd(t_input *input)
{
	int		i;

	i = -1;
	if (final_letter_is_pipe(input->cmd_line) == 1)
		fill_last_pipe(input);
	input->cmd_tab = ft_mini_split(input, input->cmd_line, '|');
	assign_garbage_type(input, input->cmd_tab, CMD_TAB);
	input->n_cmd = 0;
	while (input->cmd_tab[++i])
	{
		input->cmd_tab[i] = ft_strtrim(input, input->cmd_tab[i], " \t\n\v\f\r");
		input->garbage->type = CMD_TAB;
		input->n_cmd ++;
	}
}

int	final_letter_is_pipe(char *str)
{
	int		i_end;

	i_end = ft_strlen(str);
	while (is_space(str[i_end - 1]) == 1)
		i_end --;
	if (str[i_end - 1] == '|')
		return (1);
	else
		return (0);
}

void	fill_last_pipe(t_input *input)
{
	char	*line;
	char	*filled_cmd;

	line = readline("> ");
	filled_cmd = ft_strjoin(input, input->cmd_line, line);
	input->garbage->type = GARBAGE;
	env_converter (input, filled_cmd);
	input->cmd_line = ft_strdup(input, input->processed_line);
	input->garbage->type = CMD_LINE;
	if (final_letter_is_pipe(line) == 1)
	{
		ft_free((void *)&line);
		fill_last_pipe(input);
	}
	ft_free((void *)&line);
}