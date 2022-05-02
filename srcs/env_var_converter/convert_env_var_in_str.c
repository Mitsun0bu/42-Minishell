/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_env_var_in_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:36:44 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/20 11:29:40 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	check_heredoc(char *str, int i);

char	*convert_env_var_in_str(t_input *input, char *str)
{
	char	*line;
	int		i;
	int		red;

	red = 0;
	i = 0;
	line = ft_strdup(input, "");
	input->gb->type = GARBAGE;
	// ligne 26 a supprimer potentiellement
	while (str[i])
	{
		if (str[i] == '$' && str[i])
			line = ft_strjoin(input, line, convert_env_var(input, str, &i, red));
		else if (ft_strchr("\"\'", str[i]) && str[i])
			line = ft_strjoin(input, line, copy_env_var_in_quote(input, str, &i, red));
		else if (!ft_strchr("$\"\'", str[i]) && str[i])
			line = ft_strjoin(input, line, copy_basic_char(input, str, &i, &red));
		input->gb->type = GARBAGE;
		if (check_heredoc(str, i))
			red = HEREDOC;
	}
	return (line);
}

static int	check_heredoc(char *str, int i)
{
	int	j;

	j = i - 1;
	while (j != 0 && is_space(str[j]))
		j--;
	if (j != 0 && str[j] == '<')
		if (j > 0 && str[j - 1] == '<')
			return (1);
	return (0);
}
