/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_separator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:29:56 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/21 11:31:51 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	single_cmd(t_input *input)
{
	// input->cmd_tab = malloc (sizeof(char *) * 2);
	// if (!input->cmd_tab)
	// 	return (1);
	input->cmd_tab = safe_malloc (sizeof(char *), 2);
	input->cmd_tab[0] = ft_strdup(input->cmd_line);
	input->cmd_tab[0] = ft_strtrim(input->cmd_tab[0], " ");
	input->cmd_tab[1] = 0;
	input->n_cmd = 1;
	return (0);
}

int	split_multi_cmd(t_input *input)
{
	int		i;

	i = -1;
	input->cmd_tab = ft_split(input->cmd_line, '|');
	if (!input->cmd_tab)
		return (1);
	if (final_pipe_case(input) == 1)
		return (0);
	input->n_cmd = 0;
	while (input->cmd_tab[++i])
	{
		input->cmd_tab[i] = ft_strtrim(input->cmd_tab[i], " ");
		input->n_cmd ++;
	}
	return (0);
}

int	final_pipe_case(t_input *input)
{
	int		size;
	char	**buff;
	int		i;

	if (input->cmd_line[ft_strlen(input->cmd_line) - 1] != '|')
		return (0);
	size = bidim_tab_size(input->cmd_tab);
	// buff = malloc((size + 2) * sizeof(char *));
	// if (!buff)
	// 	return (2);
	buff = safe_malloc(sizeof(char *), (size + 2));
	i = -1;
	while (++i < size)
		buff[i] = ft_strdup(input->cmd_tab[i]);
	buff[i] = ft_strdup("");
	i ++;
	buff[i] = 0;
	// free_double(input->cmd_tab);
	input->cmd_tab = buff;
	input->n_cmd = size + 1;
	return (1);
}
