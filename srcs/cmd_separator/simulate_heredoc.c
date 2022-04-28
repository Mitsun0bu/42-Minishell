/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:46:05 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/21 14:41:00 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char **find_del(t_input *input, char *str, int n_del, char **del_tab);
static int	simulate_heredoc_prompt(t_input *input, char **del_tab);
static int	get_fake_heredoc_str(t_input *input, char *del);
static int	get_str_from_child(t_input *input, char *del, char *str);

void	simulate_heredoc(t_input *input)
{
	int	i;
	char	*cmd_line_ok;
	int		n_del;
	char	**del_tab;

	i = input->i_syntax_err + 1;
	while (ft_strchr("<>", input->cmd_line[--i]))
		input->i_syntax_err --;
	cmd_line_ok = ft_substr(input, input->cmd_line, 0, input->i_syntax_err);
	input->gb->type = GARBAGE;
	n_del = count_n_file(cmd_line_ok, HEREDOC);
	del_tab = ft_calloc(input, sizeof(char *), n_del + 1);
	input->gb->type = GARBAGE;
	del_tab = find_del(input, cmd_line_ok, n_del, del_tab);
	simulate_heredoc_prompt(input, del_tab);
}

static char **find_del(t_input *input, char *str, int n_del, char **del_tab)
{
	int	i;
	int	len;

	i = -1;
	while (++i < n_del)
	{
		len = count_filename_len(str, i, '<', HEREDOC);
		del_tab[i] = ft_calloc(input, sizeof(char), len + 1);
		input->gb->type = GARBAGE;
		copy_filename(del_tab[i], str, i, '<');
	}
	return (del_tab);
}

static int	simulate_heredoc_prompt(t_input *input, char **del_tab)
{
	int	i;

	i = -1;
	while (del_tab[++i])
	{
		if (get_fake_heredoc_str(input, del_tab[i]) == FAILED)
			return (FAILED);
	}
	return (SUCCESS);
}

static int	get_fake_heredoc_str(t_input *input, char *del)
{
	int		status;
	char	*str;
	pid_t	fake_pid;

	str = NULL;
	fake_pid = fork();
	check_fork_error(fake_pid);
	if (fake_pid == CHILD)
		status = get_str_from_child(input, del, str);
	waitpid(fake_pid, &status, 0);
	return (status);
}

static int	get_str_from_child(t_input *input, char *del, char *str)
{
	int	i;

	i = -1;
	set_signals(HEREDOC);
	str = build_heredoc_str(input, del);
	if (!str)
		exit(FAILED);
	exit (0);
}