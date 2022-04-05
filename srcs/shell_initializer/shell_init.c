/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:21:26 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/05 14:36:41 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	shell_init(char **envp, t_input *input)
{
	ft_memset(input, 0, sizeof(t_input));
	tcgetattr(STDIN_FILENO, &input->old_term);
	input->new_term = input->old_term;
	input->new_term.c_lflag &= ~(ICANON | ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &input->new_term);
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
	input->env_tab = ft_calloc(input, sizeof(t_env), i);
	input->garbage->type = ENV_STRUCT;
	input->n_env = j;
	i = -1;
	j = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "OLDPWD=", 7) != 0)
		{
			++j;
			input->env_tab[j].key = find_key(input, envp[i]);
			input->env_tab[j].value = find_value(input, envp[i]);
			input->env_tab[j].type = ENV;
		}
	}
}

void	init_shlvl(t_input *input)
{
	char	*value;

	value = NULL;
	input->start_shlvl = ft_atoi(get_value(input, "SHLVL"));
	input->start_shlvl ++;
	value = ft_itoa(input, input->start_shlvl);
	change_value(input, "SHLVL", value);
	input->garbage->type = ENV_STRUCT;
}

void	init_history(t_input *input)
{
	char	*path;
	char	*cmd_line_history;

	path = get_history_path(input);
	input->fd_history = open(path, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (input->fd_history < 0)
		stderror_exit(input, -1, "error", ": couldn't open history file");
	while (1)
	{
		cmd_line_history = ft_get_next_line(input, input->fd_history);
		if (!cmd_line_history)
			break ;
		add_history(cmd_line_history);
	}
	close (input->fd_history);
}
