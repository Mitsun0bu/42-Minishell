/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:55:23 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/29 15:15:54 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_pwd(t_input *input)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd)
	{
		input->cwd = ft_strdup(input, cwd);
		input->gb->type = INPUT_STRUCT;
		ft_free((void *)&cwd);
	}
	printf("%s\n", input->cwd);
	return (0);
}
