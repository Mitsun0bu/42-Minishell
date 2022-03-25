/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_separator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:29:56 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/25 15:52:42 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	cmd_separator (t_input *input)
{
	if (!ft_strchr(input->cmd_line, '|'))
		single_cmd(input);
	else
	{
		if (check_pipe(input) == 0)
			return (0);
		split_multi_cmd(input);
	}
	if (check_basics(input) == 0)
		return (0);
	input->free_all = 1;
	// ---------------- FINAL TEST ---------------- //
	printf("====================== CMD_SEPARATOR =======================");
	int i;
	i = -1;
	printf("\n| NOMBRE DE COMMANDES = %d\n", input->n_cmd);
	while (++i < input->n_cmd)
		printf("| COMMANDE[%d] = %s\n", i, input->cmd_tab[i]);
	printf("============================================================\n");
	// ----------------- END OF TEST ---------------//
	return (1);
}

void	single_cmd(t_input *input)
{
	input->cmd_tab = ft_malloc (input, sizeof(char *), 2);
	input->garbage->type = CMD_TAB;
	input->cmd_tab[0] = ft_strtrim(input, input->cmd_line, " \t\n\v\f\r");
	input->garbage->type = CMD_TAB;
	input->cmd_tab[1] = 0;
	input->n_cmd = 1;
}

int	split_multi_cmd(t_input *input)
{
	int		i;

	i = -1;
	if (final_letter_is_pipe(input->cmd_line) == 1)
		fill_last_pipe(input);
	input->cmd_tab = ft_split(input, input->cmd_line, '|');
	input->garbage->type = CMD_TAB;
	input->n_cmd = 0;
	while (input->cmd_tab[++i])
	{
		input->cmd_tab[i] = ft_strtrim(input, input->cmd_tab[i], " \t\n\v\f\r");
		input->garbage->type = CMD_TAB;
		input->n_cmd ++;
	}
	return (0);
}

int	final_letter_is_pipe(char *str)
{
	int		i_end;

	i_end = ft_strlen(str);
	while (is_isspace(str[i_end - 1]) == 1)
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
