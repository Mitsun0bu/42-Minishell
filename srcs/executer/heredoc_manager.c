/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:38:12 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/14 19:29:32 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// int	handle_heredocs(t_input *input, t_cmd_lst *lst_node)
// {
// 	char	**del_tab;
// 	char	*heredoc_str;

// 	heredoc_str = ft_calloc(0, 0);
// 	del_tab = find_del(lst_node, input->redir_tab, lst_node->cmd_index);
// 	heredoc_str = read_heredocs(lst_node, del_tab);
// 	dup_heredoc(heredoc_str);
// 	ft_free(heredoc_str);
// 	return (0);
// }

int	handle_heredocs(t_input *input, t_cmd_lst **lst_node)
{
	t_cmd_lst	*start;
	int			i;


	start = *lst_node;
	while (++i < input->n_cmd)
	{
		// CALL THE OLD FUNCTION IN THIS LOOP TO OPEN THE PIPE_FD_HEREDOC AND COPY HEREDOC STR INSIDE
		char		**del_tab;
		char		*heredoc_str;

		heredoc_str = ft_calloc(0, 0);
		del_tab = find_del(lst_node, input->redir_tab, lst_node->cmd_index);
		heredoc_str = read_heredocs(lst_node, del_tab);
		dup_heredoc(heredoc_str);
		ft_free(heredoc_str);

		*lst_node = (*lst_node)->next;
	}
	return (0);
}



char	**find_del(t_cmd_lst *lst_node, char ****redir_tab, int cmd_index)
{
	int		i;
	char	**del_tab;

	printf("cmd_index = %d\n", cmd_index);
	del_tab = safe_malloc(sizeof(char *), lst_node->n_heredoc + 1);
	i = -1;
	while (redir_tab[cmd_index][2][++i])
		del_tab[i] = ft_strdup(redir_tab[cmd_index][2][i]);
	return (del_tab);
}

char	*read_heredocs(t_cmd_lst *lst_node, char **del)
{
	int		i;
	char	*line;
	char	*heredoc_str;

	heredoc_str = ft_calloc(0, 0);
	i = -1;
	while (++i < lst_node->n_heredoc)
	{
		if (i == 0)
		{
			line = read_heredoc_line();
			if (ft_strncmp(line, del[i], ft_strlen(del[i])) != 0
				|| ft_strlen(line) - 1 != ft_strlen(del[i]))
				heredoc_str = ft_strdup(line);
		}
		while (ft_strncmp(line, del[i], ft_strlen(del[i])) != 0
			|| ft_strlen(line) - 1 != ft_strlen(del[i]))
		{
			line = read_heredoc_line();
			if (ft_strncmp(line, del[i], ft_strlen(del[i])) != 0
				|| ft_strlen(line) - 1 != ft_strlen(del[i]))
				heredoc_str = append_heredoc_line(line, heredoc_str);
		}
	}
	return (heredoc_str);
}

char	*read_heredoc_line(void)
{
	char	*line;
	char	*buffer;

	line = readline("> ");
	buffer = line;
	line = ft_strjoin(buffer, "\n");
	ft_free(buffer);
	return (line);
}

char	*append_heredoc_line(char *line, char *heredoc_str)
{
	char	*new_heredoc_str;
	char	*buffer;

	buffer = heredoc_str;
	ft_free(heredoc_str);
	new_heredoc_str = ft_strjoin(buffer, line);
	return (new_heredoc_str);
}