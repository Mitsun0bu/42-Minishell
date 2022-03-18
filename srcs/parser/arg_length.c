/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:31:30 by agirardi          #+#    #+#             */
/*   Updated: 2022/03/18 15:20:59 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	count_quote(char *str, int *i, int *count, int red)
{
	char	c;

	c = str[*i];
	if (red == 0)
		*count = *count + 1;
	while (str[++ *i] != c)
	{
		if (red == 0)
			*count = *count + 1;
	}
}

int	get_arg_len(char *str, int *i)
{
	int		count;
	int		red;

	red = 0;
	count = 0;
	while (str[++ *i])
	{
		while (!ft_strchr("\t\n\v\f\r <>", str[*i]) && str[*i])
		{
			if (ft_strchr("\"\'", str[*i]))
				count_quote(str, i, &count, red);
			if (red == 0)
				count++;
			if (ft_strchr("\t\n\v\f\r <>", str[*i + 1]) && red == 0)
				return (count);
			(*i)++;
		}
		red = 0;
		if (ft_strchr("<>", str[*i]))
			red = 1;
		if (ft_strchr("<>", str[*i]))
			while (ft_strchr("\t\n\v\f\r <>", str[*i + 1]))
				(*i)++;
	}
	return (count);
}

void	copy_quote(char *cmd, char *exec_cmd, int *i, int *j)
{
	char	c;

	c = cmd[*i];
	exec_cmd[(*j)++] = cmd[(*i)++];
	while (cmd[(*i)])
	{
		if (cmd[*i] == c)
		{
			exec_cmd[*j] = cmd[*i];
			break ;
		}
		exec_cmd[(*j)++] = cmd[(*i)++];
	}
	(*j)++;
	(*i)++;
}

void	fill_tab(char *cmd, char *exec_cmd, int i)
{
	int	red;
	int	j;

	red = 0;
	j = 0;
	while (cmd[++i])
	{
		while (!ft_strchr("\t\n\v\f\r <>", cmd[i]) && cmd[i])
		{
			if (ft_strchr("\"\'", cmd[i]))
			{
				if (red == 1)
					skip_quotes(cmd, &i);
				else
				{
					copy_quote(cmd, exec_cmd, &i, &j);
					printf("cmd[%d] = %c\n",i, cmd[i]);
				}
				if (!cmd[i] || ft_strchr("\t\n\v\f\r <>", cmd[i]))
					return ;
			}
			if (red == 0 && !ft_strchr("\t\n\v\f\r <>", cmd[i]))
				exec_cmd[j++] = cmd[i];
			if (!end_check(cmd, &i, &red))
				return ;
		}
		check_red(&red, cmd, &i);
	}
}