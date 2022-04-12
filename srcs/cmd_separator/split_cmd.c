/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:37:12 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/12 18:15:31 by llethuil         ###   ########lyon.fr   */
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
	pid_t	final_pipe_process;

	filled_cmd = NULL;
	if (open_single_pipe(final_pipe_fd) == FAILED)
		return (FAILED);
	final_pipe_process = fork();
	check_fork_error(final_pipe_process);
	if (final_pipe_process == 0)
		input->status = fill_cmd_child(input, filled_cmd, final_pipe_fd);
	signal(SIGINT, SIG_IGN);
	close(final_pipe_fd[1]);
	waitpid(final_pipe_process, &input->status, 0);
	if (input->status != 0)
		return (input->status);
	filled_cmd = ft_get_next_line(input, final_pipe_fd[0]);
	signal(SIGINT, signal_handler_parent);
	input->cmd_line = ft_strdup(input, filled_cmd);
	input->gb->type = CMD_LINE;
	return (input->status);
}

int	fill_cmd_child(t_input *input, char *filled_cmd, int *final_pipe_fd)
{
	char	*line;

	signal(SIGINT, SIG_DFL);
	while (1)
	{
		line = readline("> ");
		if (!line)
			stderror_exit(input, 258, "syntax error", "unexepcted end of file");
		if (ft_strlen(line))
			break ;
	}
	filled_cmd = ft_strjoin(input, input->cmd_line, line);
	input->gb->type = GARBAGE;
	if (final_letter_is_pipe(line) == 1)
	{
		ft_free((void *)&line);
		fill_cmd_child(input, filled_cmd, final_pipe_fd);
	}
	ft_putstr_fd(filled_cmd, final_pipe_fd[1]);
	close_single_pipe(final_pipe_fd);
	ft_free((void *)&line);
	exit (SUCCESS);
}
