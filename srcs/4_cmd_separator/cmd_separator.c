/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_separator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:29:56 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/21 15:03:28 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	cmd_separator(t_input *input)
{
	if (check_pipe(input) == FAILED)
	{
		printf("minishelled: syntax error near unexpected token `|'\n");
		return (FAILED);
	}
	if (split_cmd(input) == FAILED)
		return (FAILED);
	if (check_quotes(input) == FAILED)
		return (FAILED);
	if (check_redir(input) == FAILED)
	{
		simulate_heredoc(input);
		return (FAILED);
	}
	return (SUCCESS);
}
