/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:19:30 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/15 19:02:46 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "main.h"

void	ft_pwd(t_input *input)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (input->n_cmd != 1)
		printf("pwd: too many arguments\n");
	else
		printf("%s\n", cwd);
	free (cwd);
}

void	ft_echo(t_input *input)
{
	int		i;
	char	*message;

	i = 0;
	message = ft_calloc(0, 0);
	if (!input->cmd_exec_tab[0][1])
		printf("\n");
	else if (ft_strncmp(input->cmd_exec_tab[0][1], "-n", 2) == 0
		&& !input->cmd_exec_tab[0][2])
		return ;
	else
	{
		while (++i < input->n_cmd + 1)
		{
			if (ft_strncmp(input->cmd_exec_tab[0][1], "-n", 2) == 0)
				i ++;
			message = ft_strjoin(message, input->cmd_exec_tab[0][i]);
		}
		printf("%s", message);
		if (ft_strncmp(input->cmd_exec_tab[0][1], "-n", 2) != 0)
			printf("\n");
	}
	free (message);
}

int	ft_cd(t_input *input)
{
	if (access(input->cmd_exec_tab[0][1], F_OK) == 0)
		chdir(input->cmd_exec_tab[0][1]);
	else
	{
		printf("chdir: no such file or directory:");
		printf("%s\n", input->cmd_exec_tab[0][1]);
		return (1);
	}
	return (0);
}

int	ft_export(t_input *input)
{
	(void)input;
	return (0);
}

int	ft_unset(t_input *input)
{
	(void)input;
	return (0);
}

int	ft_env(t_input *input)
{
	(void)input;
	return (0);
}

int	ft_exit(t_input *input)
{
	(void)input;
	return (0);
}