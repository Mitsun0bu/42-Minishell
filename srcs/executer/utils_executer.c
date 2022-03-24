/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_executer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:32:59 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/24 12:15:45 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	find_built_in(char *name)
{
	if (!name)
		return (0);
	else if (!ft_strncmp(name, "cd", 2) && !name[2])
		return (BUILT_IN);
	else if (!ft_strncmp(name, "echo", 4) && !name[4])
		return (BUILT_IN);
	else if (!ft_strncmp(name, "pwd", 3) && !name[3])
		return (BUILT_IN);
	else if (!ft_strncmp(name, "env", 3) && !name[3])
		return (BUILT_IN);
	else if (!ft_strncmp(name, "exit", 4) && !name[4])
		return (BUILT_IN);
	else if (!ft_strncmp(name, "export", 6) && !name[6])
		return (BUILT_IN);
	else if (!ft_strncmp(name, "unset", 5) && !name[5])
		return (BUILT_IN);
	else if (!ft_strncmp(name, "./", 2))
		return (PROGRAM);
	else
		return (0);
}

void	check_fork_error(pid_t	process)
{
	if (process < 0)
	{
		perror("");
		exit (1);
	}
}

int	wait_all_processes(t_input *input)
{
	int	status;
	int	i;

	status = 0;
	i = -1;
	while (++i < input->n_cmd)
	{
		waitpid(input->process[i], &status, 0);
		printf("| STATUS PROCESS %d = %d\n", i, status);
	}
	return (status);
}

char	**convert_env_tab(t_input *input)
{
	int		i_list;
	char	**env_list;
	int		i;
	char	*env_str;

	i_list = count_env_to_convert(input);
	env_list = ft_malloc(input, sizeof(char *), i_list + 1);
	input->garbage->type = GARBAGE;
	env_list[i_list] = NULL;
	i = -1;
	while(++i < i_list)
	{
		if (input->env_tab[i].type == ENV || input->env_tab[i].type == EXPORT_EMPTY)
		{
			env_str = ft_strjoin(input, input->env_tab[i].key, "=");
			input->garbage->type = GARBAGE;
			env_str = ft_strjoin(input, env_str, input->env_tab[i].value);
			input->garbage->type = GARBAGE;
			env_list[i] = ft_strdup(input, env_str);
			input->garbage->type = GARBAGE;
		}
		else
			i ++;
	}
	return (env_list);
}

int	count_env_to_convert(t_input *input)
{
	int	i;
	int	i_list;

	i = -1;
	i_list = 0;
	while (++i < input->n_env)
		if (input->env_tab[i].type == ENV || input->env_tab[i].type == EXPORT_EMPTY)
			i_list ++;
	return (i_list);
}

