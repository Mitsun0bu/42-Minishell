/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_history_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:22:49 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/14 12:46:40 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*get_history_path(t_input *input)
{
	char	*path;

	if (!get_value_from_key(input, "HOME"))
		return (NULL);
	path = ft_strjoin(input, get_value_from_key(input, "HOME"), "/.minishelled_history");
	input->gb->type = GARBAGE;
	return (path);
}
