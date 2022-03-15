/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:55:23 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/15 11:25:37 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_pwd(t_cmd_lst *cmd)
{
	(void)cmd;
	char	*cwd;

	cwd = getcwd(NULL, 0);

	printf("%s\n", cwd);
	ft_free (cwd);
	return (0);
}
