/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_history_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:22:49 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/20 10:10:10 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*get_history_path(t_input *input)
{
	char	*path;
	char	*home;

	home = get_value_from_key(input, "HOME");
	if (!home)
		return (NULL);
	path = ft_strjoin(input, home, "/.minishelled_history");
	input->gb->type = GARBAGE;
	return (path);
}
