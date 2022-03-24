/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:31:04 by agirardi          #+#    #+#             */
/*   Updated: 2022/03/24 10:15:52 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	handle_quote(char *str, int *i, int *count, int *red)
{
	if (*i > 0 && str[*i - 1] == ' ' && *red == 0)
		*count = *count + 1;
	if (*red == 1)
		*red = 0;
	skip_quotes(str, i);
}

int	get_arg_num(char *str)
{
	int	red;
	int	count;
	int	i;

	count = 0;
	red = 0;
	i = -1;
	while (str[++i])
	{
		if (ft_strchr("\"\'", str[i]))
			handle_quote(str, &i, &count, &red);
		if (ft_strchr("<>", str[i]))
			red = 1;
		if ((ft_isalnum(str[i]) || ft_strchr("-./\\", str[i]))
			&& (i == 0 || ft_strchr(" <>", str[i - 1])))
		{
			if (red == 1)
				red = 0;
			else
				count++;
		}
	}
	return (count);
}

int	create_arg_tab(t_input *input, int i)
{
	int	start;
	int	len;
	int	buff_start;
	int	j;

	start = -1;
	len = 0;
	j = -1;
	while (++j < get_arg_num(input->cmd_tab[i]))
	{
		buff_start = start;
		len = get_arg_len(input->cmd_tab[i], &start) + 1;
		input->cmd_exec_tab[i][j] = ft_calloc(input, sizeof(char), len);
		input->garbage->type = INPUT_STRUCT;
		fill_tab(input->cmd_tab[i], input->cmd_exec_tab[i][j], buff_start);
	}
	return (1);
}