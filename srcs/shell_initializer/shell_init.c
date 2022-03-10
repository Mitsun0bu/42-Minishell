/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:21:26 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/10 11:12:45 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	shell_init(int ac, char **envp, t_input *input, t_cmd_lst **lst_node)
{
	if (ac > 1)
	{
		printf("To start our shell, use : ./minishell !\n");
		exit(0);
	}
	if (isatty(STDIN_FILENO) == 0)
	{
		perror("");
		exit (0);
	}
	ft_memset(input, 0, sizeof(input));
	ft_memset(lst_node, 0, sizeof(lst_node));
	init_message();
	init_env(input, envp);
	init_shlvl(input);
	init_history(input);
}

void	init_message(void)
{
	printf("███╗░░░███╗██╗███╗░░██╗██╗░██████╗██╗░░██╗");
	printf("███████╗██╗░░░░░██╗░░░░░███████╗██████╗░\n");
	printf("████╗░████║██║████╗░██║██║██╔════╝██║░░██║");
	printf("██╔════╝██║░░░░░██║░░░░░██╔════╝██╔══██╗\n");
	printf("██╔████╔██║██║██╔██╗██║██║╚█████╗░███████║");
	printf("█████╗░░██║░░░░░██║░░░░░█████╗░░██║░░██║\n");
	printf("██║╚██╔╝██║██║██║╚████║██║░╚═══██╗██╔══██║");
	printf("██╔══╝░░██║░░░░░██║░░░░░██╔══╝░░██║░░██║\n");
	printf("██║░╚═╝░██║██║██║░╚███║██║██████╔╝██║░░██║");
	printf("███████╗███████╗███████╗███████╗██████╔╝\n");
	printf("╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝╚═════╝░╚═╝░░╚═╝");
	printf("╚══════╝╚══════╝╚══════╝╚══════╝╚═════╝░\n");
	printf("\n");
}

void	init_env(t_input *input, char **envp)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	while (envp[++i])
		if (ft_strncmp(envp[i], "OLDPWD=", 7) != 0)
			j++;
	input->env_tab = safe_malloc(sizeof(t_env), i);
	input->n_env = j;
	i = -1;
	j = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "OLDPWD=", 7) != 0)
		{
			++j;
			input->env_tab[j].key = find_key(envp[i]);
			input->env_tab[j].value = find_value(envp[i]);
			input->env_tab[j].type = ENV;
		}
	}
}

void	init_shlvl(t_input *input)
{
	char	*value;

	value = ft_strdup(get_value("SHLVL", input));
	input->start_shlvl = ft_atoi(value);
	input->start_shlvl ++;
	value = ft_itoa(input->start_shlvl);
	change_value(input, "SHLVL", value);
}

int	init_history(t_input *input)
{
	char	*cmd_line_history;
	char	*path;

	path = get_history_path(input);
	input->fd_history = open(path, O_CREAT | O_RDWR | O_APPEND, 0644);
	ft_free(path);
	if (input->fd_history < 0)
	{
		printf("Couldn't open history file");
		exit(0);
	}
	cmd_line_history = "init";
	while (cmd_line_history)
	{
		cmd_line_history = get_next_line(input->fd_history);
		add_history(cmd_line_history);
		ft_free(cmd_line_history);
	}
	close (input->fd_history);
	return (0);
}
