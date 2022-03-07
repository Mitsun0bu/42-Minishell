/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:58:04 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/07 11:39:01 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	path_manager(char **envp, t_input *input, t_cmd_lst **lst_node)
{
	t_cmd_lst	*start;

	start = *lst_node;
	get_paths_tab(envp, input);
	while (*lst_node)
	{
		// Reflechir à l'utilite du premier parametre de la fonction assign_path dans minishell
		if (ft_strncmp((*lst_node)->cmd_name, "export", 6) == 0)
			(*lst_node)->valid_path = ft_strdup("export");
		else if (ft_strncmp((*lst_node)->cmd_name, "unset", 5) == 0)
			(*lst_node)->valid_path = ft_strdup("unset");
		else
			(*lst_node)->valid_path = assign_path("test", input, *lst_node);
		*lst_node = (*lst_node)->next;
	}
	*lst_node = start;
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

char	*assign_path(char *arg, t_input *input, t_cmd_lst *lst_node)
{
	int		i;
	char	*path;

	i = -1;
	while (input->paths_tab[++i])
	{
		(void)arg;
		// if (access(arg, F_OK) == 0)
		// 	return (arg);
		path = ft_strjoin(input->paths_tab[i], lst_node->cmd_name);
		if (access(path, F_OK) == 0)
			return (path);
		ft_free(path);
	}
	// if (access(path, F_OK) == -1 && cmd_name == cmd->name_1[0])
	// 	error_handler(av, ERR_CMD_1);
	// if (access(path, F_OK) == -1 && cmd_name == cmd->name_2[0])
	// 	error_handler(av, ERR_CMD_2);
	return (NULL);
}
