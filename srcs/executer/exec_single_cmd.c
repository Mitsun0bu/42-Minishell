/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_single_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:51:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/14 12:18:43 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/main.h"
#include "built_ins.h"

void	exec_single_cmd(t_input *input)
{
	if (ft_strncmp(input->cmd_tab[0], "pwd", 3) == 0)
		ft_pwd(input);
	else if (ft_strncmp(input->cmd_tab[0], "echo", 4) == 0)
		ft_echo(input);
	else if (ft_strncmp(input->cmd_tab[0], "cd", 2) == 0)
		ft_cd(input);
	else
	{
		printf("Yes there is only one single cmd !");
		printf("But it is not pwd or echo so I can't execute it yet\n");
	}
	return ;
}
