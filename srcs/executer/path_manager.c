/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:58:04 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/22 12:15:10 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	path_manager(char **av, char **envp, t_input *input, t_cmd_lst **lst_head)
{
	t_cmd_lst	*start;

	start = *lst_head;
	get_paths_tab(envp, input);
	while (*lst_head)
	{
		(*lst_head)->valid_path = assign_path(av, "test", input, *lst_head);
		*lst_head = (*lst_head)->next;
	}
	*lst_head = start;
}

void	get_paths_tab(char **envp, t_input	*input)
{
	int		i;
	char	*paths_line;
	char	*buff;

	i = -1;
	paths_line = NULL;
	while (*envp)
	{
		if (ft_strnstr(*envp, "PATH=", 5) != NULL)
		{
			paths_line = ft_substr(*envp, 5, ft_strlen(*envp));
			break ;
		}
		envp++;
	}
	input->paths_tab = ft_split(paths_line, ':');
	while (input->paths_tab[++i])
	{
		buff = input->paths_tab[i];
		input->paths_tab[i] = ft_strjoin(input->paths_tab[i], "/");
		free (buff);
	}
	ft_free(paths_line);
}

char	*assign_path(char **av, char *arg, t_input *input, t_cmd_lst *lst_head)
{
	int		i;
	char	*path;

	i = -1;
	while (input->paths_tab[++i])
	{
		(void)arg;
		// if (access(arg, F_OK) == 0)
		// 	return (arg);
		path = ft_strjoin(input->paths_tab[i], lst_head->cmd_name);
		if (access(path, F_OK) == 0)
			return (path);
		ft_free(path);
	}
	(void)av;
	// if (access(path, F_OK) == -1 && cmd_name == cmd->name_1[0])
	// 	error_handler(av, ERR_CMD_1);
	// if (access(path, F_OK) == -1 && cmd_name == cmd->name_2[0])
	// 	error_handler(av, ERR_CMD_2);
	return (NULL);
}