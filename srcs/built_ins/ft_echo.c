/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:55:57 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/03 14:49:24 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "main.h"

int	ft_echo(t_cmd_lst *lst_node)
{
	int		i;
	char	*message;

	i = 0;
	message = ft_calloc(0, 0);
	if (!lst_node->cmd_args[1])
		printf("\n");
	else if (ft_strncmp(lst_node->cmd_args[1], "-n", 2) == 0 && !lst_node->cmd_args[2])
		return (1);
	else
	{
		if (ft_strncmp(lst_node->cmd_args[1], "-n", 2) == 0)
			i ++;
		while (++i < lst_node->n_args)
		{
			message = ft_strjoin(message, lst_node->cmd_args[i]);
			if (i != lst_node->n_args - 1)
			message = ft_strjoin(message, " ");
		}
		print_message(message);
		if (ft_strncmp(lst_node->cmd_args[1], "-n", 2) != 0)
			printf("\n");
	}
	ft_free (message);
	return (0);
}

void	print_message(char *message)
{
	size_t	i;

	i = -1;
	while (++i < ft_strlen(message))
	{
		if (message[i] == '\'')
		{
			while (message[++i] != '\'')
				write(1, &message[i], 1);
			if (message[i] == '\'')
				i ++;
		}
		else if (message[i] == '\"')
		{
			while (message[++i] != '\"')
				write(1, &message[i], 1);
			if (message[i] == '\"')
				i ++;
		}
		write(1, &message[i], 1);
	}
}