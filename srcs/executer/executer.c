/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:51:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/10 11:13:17 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	executer(char **envp, t_input *input, t_cmd_lst **lst_node)
{
	int	status;

	status = 0;
	path_manager(envp, input, lst_node);
	open_files(lst_node);
	open_all_pipes(lst_node);
	// convert_env_tab(input);
	if (input->n_cmd == 1 && find_built_in((*lst_node)->cmd_name) == BUILT_IN)
	{
		handle_output_redir(input, *lst_node);
		status = exec_built_in(input, *lst_node);
		dup2(STDIN_FILENO, STDOUT_FILENO);
	}
	else
		status = pipex(envp, input, lst_node);
	printf(" - - - - - - - - - - - - - - - - - - - \n");
	return (status);
}

char	**convert_env_tab(t_input *input)
{
	char	**env_list;
	char	*buffer;
	char	*env_str;
	int		i_list;
	int		i;
	// int		j;

	i_list = 0;
	i = -1;
	while (++i < input->n_env)
	{
		if (input->env_tab[i].type == ENV || input->env_tab[i].type == EXPORT_EMPTY)
			i_list ++;
	}
	env_list = safe_malloc(sizeof(char), i_list);
	env_list[i_list] = 0;
	printf("========== ENV_LIST ==========\n");
	i = -1;
	while(env_list[++i])
	{
		printf("here[%d]\n", i);
		if (input->env_tab[i].type == ENV || input->env_tab[i].type == EXPORT_EMPTY)
		{
			buffer = ft_strjoin(input->env_tab[i].key, "=");
			env_str = ft_strjoin(buffer, input->env_tab[i].value);
			ft_free(buffer);
			printf("| %d. env_str = %s\n", i, env_str);
			ft_free(env_str);
		}
	}
	// env_list[i] = safe_malloc(sizeof(char), ft_strlen(env_str) + 1);
	// j = -1;
	// while (env_str[++j])
	// 	env_list[i][j] = env_str[j];
	// env_list[i][j] = '\0';
	// 	// ft_free(env_str);
	// i = -1;
	// while (env_str[++i])
	// 	printf("| %d. env_list = %s\n", i, env_list[i]);
	return (env_list);
}
