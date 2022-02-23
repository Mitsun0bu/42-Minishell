/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:55:23 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/23 14:25:11 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "main.h"

void	ft_pwd(t_cmd_lst *lst_node)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (lst_node->n_args != 1)
		printf("pwd: too many arguments\n");
	else
		printf("%s\n", cwd);
	ft_free (cwd);
	// Voir comment gerer le cas d'erreur
}