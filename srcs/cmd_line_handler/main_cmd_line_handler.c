/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cmd_line_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:33:25 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/11 11:56:28 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cmd_line_handler.h"

void	main_cmd_line_handler(t_input *input)
{
	static int turn = 0;
	int	fd;

	fd = open_history_file();
	if (turn == 0)
	{
		get_history(fd);
		turn ++;
	}
	get_cmd_line(input, fd);
	close(fd);
	return ;
}
