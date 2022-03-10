/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_executer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:32:59 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/10 18:17:25 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	find_built_in(char *cmd_name)
{
	if (!ft_strncmp(cmd_name, "cd", 2) && !cmd_name[2])
		return (BUILT_IN);
	else if (!ft_strncmp(cmd_name, "echo", 4) && !cmd_name[4])
		return (BUILT_IN);
	else if (!ft_strncmp(cmd_name, "pwd", 3) && !cmd_name[3])
		return (BUILT_IN);
	else if (!ft_strncmp(cmd_name, "env", 3) && !cmd_name[3])
		return (BUILT_IN);
	else if (!ft_strncmp(cmd_name, "exit", 4) && !cmd_name[4])
		return (BUILT_IN);
	else if (!ft_strncmp(cmd_name, "export", 6) && !cmd_name[6])
		return (BUILT_IN);
	else if (!ft_strncmp(cmd_name, "unset", 5) && !cmd_name[5])
		return (BUILT_IN);
	else if (!ft_strncmp(cmd_name, "./", 2))
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
	char	**env_list;
	char	*buffer;
	char	*env_str;
	int		i_list;
	int		i;

	i_list = count_env_to_convert(input);
	env_list = safe_malloc(sizeof(char *), i_list + 1);
	env_list[i_list] = NULL;
	i = -1;
	while(++i < i_list)
	{
		if (input->env_tab[i].type == ENV || input->env_tab[i].type == EXPORT_EMPTY)
		{
			buffer = ft_strjoin(input->env_tab[i].key, "=");
			env_str = ft_strjoin(buffer, input->env_tab[i].value);
			ft_free(buffer);
			env_list[i] = ft_strdup(env_str);
			ft_free(env_str);
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

