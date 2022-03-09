/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:55:23 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/09 15:12:52 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_pwd(t_cmd_lst *lst_node)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (lst_node->n_args != 1)
		printf("pwd: too many arguments\n");
	else
		printf("%s\n", cwd);
	ft_free (cwd);
	return (0);
	// Voir comment gerer le cas d'erreur
}
