/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:37:12 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/25 19:30:40 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	final_letter_is_pipe(char *str);
static int	fill_cmd(t_input *input);
static int	fill_cmd_child(t_input *input, char *filled_cmd, int *pipe_fd);

int	split_cmd(t_input *input)
{
	int	i;

	i = -1;
	if (final_letter_is_pipe(input->cmd_line) == YES)
		if (fill_cmd(input) != 0)
			return (FAILED);
	input->cmd_tab = ft_mini_split(input, input->cmd_line, '|');
	assign_gb_type(input, input->cmd_tab, CMD_TAB);
	input->n_cmd = 0;
	while (input->cmd_tab[++i])
	{
		input->cmd_tab[i] = ft_strtrim(input, input->cmd_tab[i], " \t\n\v\f\r");
		input->gb->type = CMD_TAB;
		input->n_cmd ++;
	}
	return (SUCCESS);
}

static int	final_letter_is_pipe(char *str)
{
	int		i_end;

	i_end = ft_strlen(str);
	while (is_space(str[i_end - 1]) == YES)
		i_end --;
	if (str[i_end - 1] == '|')
		return (YES);
	else
		return (NO);
}

static int	fill_cmd(t_input *input)
{
	char	*filled_cmd;
	int		pipe_fd[2];
	pid_t	final_pipe_process;

	filled_cmd = NULL;
	if (open_single_pipe(pipe_fd) == FAILED)
		return (FAILED);
	set_signals(EXEC);
	final_pipe_process = fork();
	check_fork_error(final_pipe_process);
	if (final_pipe_process == CHILD)
		g_status = fill_cmd_child(input, filled_cmd, pipe_fd);
	close(pipe_fd[1]);
	waitpid(final_pipe_process, &g_status, 0);
	set_signals(MAIN);
	filled_cmd = ft_get_next_line(input, pipe_fd[0]);
	if (g_status != 0 || !filled_cmd)
		return (g_status);
	input->cmd_line = ft_strdup(input, filled_cmd);
	input->gb->type = CMD_LINE;
	return (g_status);
}

static int	fill_cmd_child(t_input *input, char *filled_cmd, int *pipe_fd)
{
	char	*line;

	set_signals(PIPE);
	while (1)
	{
		line = readline("> ");
		if (!line)
			exit_err(input, 258, "syntax error", "unexpected end of file");
		if (ft_strlen(line))
			break ;
	}
	filled_cmd = ft_strjoin(input, input->cmd_line, line);
	input->gb->type = GARBAGE;
	if (final_letter_is_pipe(line) == YES)
	{
		ft_free((void *)&line);
		fill_cmd_child(input, filled_cmd, pipe_fd);
	}
	ft_putstr_fd(filled_cmd, pipe_fd[1]);
	close_single_pipe(pipe_fd);
	ft_free((void *)&line);
	exit (SUCCESS);
}
