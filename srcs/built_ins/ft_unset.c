/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:40:20 by agirardi          #+#    #+#             */
/*   Updated: 2022/04/19 18:53:50 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_unset(t_input *input, t_cmd_lst *cmd)
{
	char	*key;
	int		i;

	if (input->n_cmd > 1)
		return (0);
	i = 0;
	while (cmd->args[++i])
	{
		key = cmd->args[i];
		if (parse_arg(key) == SUCCESS && find_existing_env_var(input, key) == YES)
			remove_from_env_tab(input, key);
	}
	return (0);
}

int	parse_arg(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((!ft_isalnum(str[i]) && str[i] != '_') || ft_isdigit(str[0]))
		{
			print_err(1, "minishelled: unset", str, "not a valid identifier");
			return (FAILED);
		}
	}
	return (SUCCESS);
}
