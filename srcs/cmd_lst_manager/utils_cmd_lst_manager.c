/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmd_lst_manager.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:35:14 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/07 17:27:33 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	add_cmd_back(t_cmd_lst *cmd, t_cmd_lst *new_cmd)
{
	t_cmd_lst	*start;
	t_cmd_lst	*last_cmd;

	start = cmd;
	last_cmd = find_last_cmd(cmd);
	last_cmd->next = new_cmd;
	new_cmd->previous = last_cmd;
	new_cmd->next = NULL;
	cmd = start;
}

t_cmd_lst	*find_last_cmd(t_cmd_lst *cmd)
{
	if (!cmd)
		return (NULL);
	while (cmd->next)
		cmd = cmd->next;
	return (cmd);
}

char	*clean_cmd_name(t_input *input, char *str)
{
	char	*cmd_name;
	int		size;
	int		i;
	int		j;

	size = 0;
	i = -1;
	while (++i < (int)strlen(str))
		if (!ft_strchr("\'\"", str[i]))
			size++;
	cmd_name = ft_calloc(input, sizeof(char), size + 1);
	input->garbage->type = CMD_LST;
	i = -1;
	j = -1;
	while (++i < (int)strlen(str))
		if (!ft_strchr("\'\"", str[i]))
			cmd_name[++j] = str[i];
	return (cmd_name);
}

char *clean_arg(t_input *input, char *str, int index)
{
	int	i;
	int	len;
	char *clean_str;

	i = -1;
	len = 0;
	while (str[++i])
	{
		if (!ft_strchr("\'\"", str[i]))
			len ++;
		else
			i ++;
	}
	clean_str = ft_malloc(input, sizeof(char), len + 1);
	i = -1;
	while (str[++i])
	{
		if (!ft_strchr("\'\"", str[i]))
			clean_str[i] = str[i];
		else
			i ++;
	}
	// trim les quotes fermantes
	// double quote supprimees
	// simple quote gardees
	return (clean_str);
}