/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:40:20 by agirardi          #+#    #+#             */
/*   Updated: 2022/04/06 14:25:39 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_unset(t_input *input)
{
	char	*key;
	int		i;

	if (input->n_cmd > 1)
		return (0);
	i = 0;
	while (input->cmd_exec_tab[0][++i])
	{
		key = del_quotes(input, input->cmd_exec_tab[0][i]);
		if (parse_arg(key) && check_dubble(input, key))
			remove_from_env(input, key);
	}
	return (0);
}

int	parse_arg(char *str)
{
	int	i;

	if (ft_isdigit(str[0]))
		return (0);
	i = -1;
	while (str[++i])
		if ((!ft_isalnum(str[i]) && str[i] != '_'))
			return (0);
	return (1);
}
