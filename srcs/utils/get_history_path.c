/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:22:49 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/06 14:15:19 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*get_history_path(t_input *input)
{
	char	*path;

	if (!get_value(input, "HOME"))
		return (NULL);
	path = ft_strjoin(input, get_value(input, "HOME"), "/.minishelled_history");
	input->garbage->type = GARBAGE;
	return (path);
}