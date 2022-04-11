/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:37:12 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/11 18:07:37 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	split_cmd(t_input *input)
{
	int	i;

	i = -1;
	if (final_letter_is_pipe(input->cmd_line) == TRUE)
		if (fill_cmd(input) != 0)
			return (FAILED);
	input->cmd_tab = ft_mini_split(input, input->cmd_line, '|');
	assign_garbage_type(input, input->cmd_tab, CMD_TAB);
	input->n_cmd = 0;
	while (input->cmd_tab[++i])
	{
		input->cmd_tab[i] = ft_strtrim(input, input->cmd_tab[i], " \t\n\v\f\r");
		input->garbage->type = CMD_TAB;
		input->n_cmd ++;
	}
	return (SUCCESS);
}

int	final_letter_is_pipe(char *str)
{
	int		i_end;

	i_end = ft_strlen(str);
	while (is_space(str[i_end - 1]) == 1)
		i_end --;
	if (str[i_end - 1] == '|')
		return (TRUE);
	else
		return (FALSE);
}

int	fill_cmd(t_input *input)
{
	char	*filled_cmd;
	int		final_pipe_fd[2];
	int		final_pipe_process;

	filled_cmd = NULL;
	if (open_single_pipe(final_pipe_fd) == FAILED)
		return (FAILED);
	final_pipe_process = fork();
	check_fork_error(final_pipe_process);
	if (final_pipe_process == 0)
		input->status = fill_cmd_from_child(input, filled_cmd, final_pipe_fd);
	close_single_pipe(final_pipe_fd);
	signal(SIGINT, SIG_IGN);
	waitpid(final_pipe_process, &input->status, 0);
	signal(SIGINT, signal_handler_parent);
	return (input->status);
}

int	fill_cmd_from_child(t_input *input, char *filled_cmd, int *final_pipe_fd)
{
	char	*line;

	signal(SIGINT, SIG_DFL);
	line = readline("> ");
	if (!line)
		exit (1);
	filled_cmd = ft_strjoin(input, input->cmd_line, line);
	input->garbage->type = GARBAGE;
	env_converter (input, filled_cmd);
	input->cmd_line = ft_strdup(input, input->processed_line);
	input->garbage->type = CMD_LINE;
	if (final_letter_is_pipe(line) == 1)
	{
		ft_free((void *)&line);
		fill_cmd_from_child(input, filled_cmd, final_pipe_fd);
	}
	ft_putstr_fd(filled_cmd, final_pipe_fd[1]);
	ft_free((void *)&line);
	exit (SUCCESS);
}