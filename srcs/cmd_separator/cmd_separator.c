/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_separator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:29:56 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/16 17:39:04 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	cmd_separator (t_input *input)
{
	if (!ft_strchr(input->cmd_line, '|'))
		single_cmd(input);
	else
		split_multi_cmd(input);
}

void	single_cmd(t_input *input)
{
	input->cmd_tab = safe_malloc (sizeof(char *), 2);
	input->cmd_tab[0] = ft_strdup(input->cmd_line);
	input->cmd_tab[0] = ft_strtrim(input->cmd_tab[0], " \t\n\v\f\r");
	input->cmd_tab[1] = 0;
	input->n_cmd = 1;
}

int	split_multi_cmd(t_input *input)
{
	int		i;

	i = -1;
	if (final_letter_is_pipe(input->cmd_line) == 1)
		fill_last_pipe(input);
	input->cmd_tab = ft_split(input->cmd_line, '|');
	if (!input->cmd_tab)
		return (1);
	// GERER ERREUR DE SPLIT
	input->n_cmd = 0;
	while (input->cmd_tab[++i])
	{
		input->cmd_tab[i] = ft_strtrim(input->cmd_tab[i], " \t\n\v\f\r");
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
	filled_cmd = ft_strjoin(input->cmd_line, line);
	ft_free((void *)&input->cmd_line);
	input->cmd_line = ft_strdup(filled_cmd);
	if (final_letter_is_pipe(line) == 1)
		fill_last_pipe(input);
}
