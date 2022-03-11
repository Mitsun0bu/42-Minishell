/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:45:14 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/11 19:33:25 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		handle_heredoc(t_input *input, t_cmd_lst *lst_node)
{
	int		i;
	char	**del_tab;
	char	*line;
	char	*buffer;
	char	*heredoc_str;

	line = NULL;
	buffer = NULL;
	heredoc_str = NULL;
	del_tab = find_delimiters(lst_node, input->redir_tab, lst_node->cmd_index);
	i = -1;
	while (++i < lst_node->n_heredoc)
	{
		if (i == 0)
			read_first_heredoc_line(&line, &buffer, &heredoc_str);
		while (ft_strncmp(line, del_tab[i], ft_strlen(del_tab[i])) != 0
			|| ft_strlen(line) != ft_strlen(del_tab[i]))
			read_following_heredoc_lines(del_tab[i], &line, &buffer, &heredoc_str);
	}
	dup_heredoc(heredoc_str);
	ft_free(heredoc_str);
	free_double(del_tab);
	return (0);
}

int	handle_input_redir(t_cmd_lst *lst_node)
{
	int	redir_in;

	redir_in = 0;
	if (lst_node->n_input_redir)
		redir_in = dup_redir_input(lst_node);
	return(redir_in);
}

int	handle_output_redir(t_input *input, t_cmd_lst *lst_node)
{
	int	redir_out;

	redir_out = 0;
	if (input->last_output_redir_tab[lst_node->cmd_index] == TRUNC_OUTPUT)
	{
		if (lst_node->n_app_output_redir)
			redir_out = dup_redir_app_output(lst_node);
		redir_out = dup_redir_output(lst_node);
	}
	else if (input->last_output_redir_tab[lst_node->cmd_index] == APP_OUTPUT)
	{
		if (lst_node->n_app_output_redir)
			redir_out = dup_redir_output(lst_node);
		redir_out = dup_redir_app_output(lst_node);
	}
	return (redir_out);
}

char	**find_delimiters(t_cmd_lst *lst_node, char ****redir_tab, int cmd_index)
{
	int		i;
	char	**del_tab;

	del_tab = safe_malloc(sizeof(char *), lst_node->n_heredoc + 1);
	i = -1;
	while(redir_tab[cmd_index][2][++i])
		del_tab[i] = ft_strdup(redir_tab[cmd_index][2][i]);
	return (del_tab);
}

void	read_first_heredoc_line(char **line, char **buffer, char **heredoc_str)
{
		*line = readline("> ");
		*buffer = *line;
		*heredoc_str = ft_strjoin(*buffer, "\n");
		ft_free(*buffer);
}

void	read_next_heredoc_lines(char * del, char **line, char **buffer, char **heredoc_str)
{
	*line = readline("> ");
	if (ft_strncmp(*line, del, ft_strlen(del)) != 0 || ft_strlen(*line) != ft_strlen(del))
	{
		*buffer = ft_strjoin(*heredoc_str, *line);
		ft_free(*heredoc_str);
		*heredoc_str = ft_strjoin(*buffer, "\n");
		ft_free(*buffer);
	}
}
