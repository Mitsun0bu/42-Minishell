/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:19:30 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/14 12:08:08 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins.h"

void	ft_echo(t_input *input)
{
	int		i;
	char	*message;

	i = 0;
	message = ft_calloc(0, 0);
	if (!input->cmd_tab[1])
		printf("\n");
	else if (ft_strncmp(input->cmd_tab[1], "-n", 2) == 0
		&& !input->cmd_tab[2])
		return ;
	else
	{
		if (ft_strncmp(input->cmd_tab[1], "-n", 2) == 0)
			i = 1;
		while (++i < input->n_cmd)
		{
			message = ft_strjoin(message, input->cmd_tab[i]);
			if (i != input->n_cmd - 1)
			message = ft_strjoin(message, " ");
		}
		printf("%s", message);
		if (ft_strncmp(input->cmd_tab[1], "-n", 2) != 0)
			printf("\n");
	}
	free (message);
}

int	ft_cd(t_input *input)
{
	if (access(input->cmd_tab[1], F_OK) == 0)
		chdir(input->cmd_tab[1]);
	else
	{
		printf("chdir: no such file or directory:");
		printf("%s\n", input->cmd_tab[1]);
		return (1);
	}
	return (0);
}

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
