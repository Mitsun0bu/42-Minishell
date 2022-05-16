/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:33:25 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/16 14:43:36 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	get_cmd_line(t_input *input);
static int	check_cmd_line(t_input *input);
static void	add_cmd_line_in_history(t_input *input, char *path, char *buff);

int	cmd_line_manager(t_input *input)
{
	get_cmd_line(input);
	if (check_cmd_line(input) == FAILED)
		return (FAILED);
	input->cmd_line = convert_tilde_in_str(input, input->cmd_line);
	input->gb->type = CMD_LINE;
	input->cmd_line = convert_env_var_in_str(input, input->cmd_line);
	input->gb->type = CMD_LINE;
	return (SUCCESS);
}

static void	get_cmd_line(t_input *input)
{
	char	*path;
	char	*buff;

	path = get_history_path(input);
	buff = NULL;
	while (1)
	{
		buff = readline("minishelled-1.0$ ");
		if (!buff)
			exit_err(input, 0, NULL, "exit");
		if (ft_strlen(buff))
			break ;
	}
	add_history(buff);
	if (path)
		add_cmd_line_in_history(input, path, buff);
	input->cmd_line = ft_strdup(input, buff);
	input->gb->type = CMD_LINE;
	ft_free((void *)&buff);
}

static int	check_cmd_line(t_input *input)
{
	if (check_is_space(input) == FAILED)
		return (FAILED);
	if (check_pipe(input) == FAILED)
	{
		print_err(258, NULL, NULL, "syntax error near unexpected token `|'");
		return (FAILED);
	}
	if (check_redir(input) == FAILED)
		return (FAILED);
	if (check_quotes(input) == FAILED)
		return (FAILED);
	return (SUCCESS);
}

static void	add_cmd_line_in_history(t_input *input, char *path, char *buff)
{
	input->fd_history = open(path, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (input->fd_history >= 0)
	{
		ft_putstr_fd(ft_strjoin(input, buff, "\n"), input->fd_history);
		close (input->fd_history);
	}
}
