/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:56:25 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/03 16:11:35 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "main.h"

int	ft_cd(t_cmd_lst *lst_node)
{
	if (access(lst_node->cmd_args[1], F_OK) == 0)
		chdir(lst_node->cmd_args[1]);
	else
	{
		printf("chdir: no such file or directory:");
		printf("%s\n", lst_node->cmd_args[1]);
		return (1);
	}
	// Rajouter changement de directory dans la structure env
	// Voir comment gerer le cas d'erreur
	return (0);
}