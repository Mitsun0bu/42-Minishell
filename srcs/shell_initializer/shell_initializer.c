/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:21:26 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/22 14:54:08 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	init_message(void);
static void	init_env(t_input *input, char **envp);
static void	init_shlvl(t_input *input);
static void	init_history(t_input *input);

void	shell_initializer(int ac, char **av, char **envp, t_input *input)
{
	if (ac > 1 || av[1])
	{
		print_err(127, "minishelled", av[1], "invalid option");
		exit (127);
	}
	ft_memset(input, 0, sizeof(t_input));
	set_termios(input, YES);
	set_signals(MAIN);
	init_message();
	init_env(input, envp);
	init_shlvl(input);
	init_history(input);
}

static void	init_message(void)
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

static void	init_env(t_input *input, char **envp)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	while (envp[++i])
		if (ft_strncmp(envp[i], "OLDPWD=", 7) != 0)
			j++;
	input->env_tab = ft_calloc(input, sizeof(t_env), i);
	input->gb->type = ENV_STRUCT;
	input->n_env = j;
	i = -1;
	j = -1;

	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "OLDPWD=", 7) != 0)
		{
			++j;
			input->env_tab[j].key = extract_key_from_str(input, envp[i]);
			input->env_tab[j].value = extract_value_from_str(input, envp[i]);
			input->env_tab[j].type = ENV;
		}
	}
}

static void	init_shlvl(t_input *input)
{
	char	*value;

	value = NULL;
	if (!get_value_from_key(input, "SHLVL"))
	{
		add_to_env_tab(input, "SHLVL=1", ENV);
		return ;
	}
	input->start_shlvl = ft_atoi(get_value_from_key(input, "SHLVL"));
	input->start_shlvl ++;
	value = ft_itoa(input, input->start_shlvl);
	change_value(input, "SHLVL", value);
	input->gb->type = ENV_STRUCT;
}

static void	init_history(t_input *input)
{
	char	*path;
	char	*cmd_line_history;

	path = get_history_path(input);
	if (!path)
		return ;
	input->fd_history = open(path, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (input->fd_history < 0)
		exit_err(input, -1, "error", ": couldn't open history file");
	while (1)
	{
		cmd_line_history = ft_get_next_line(input, input->fd_history);
		if (!cmd_line_history)
			break ;
		add_history(cmd_line_history);
	}
	close (input->fd_history);
}
