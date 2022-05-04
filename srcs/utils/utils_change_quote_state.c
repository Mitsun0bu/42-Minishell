/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_change_quote_state.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:54:05 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/04 19:02:33 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	change_quote_state(int	*quote_state, char quote)
{
	static char	previous_quote = 0;

	if (*quote_state == OUT)
	{
		*quote_state = IN;
		previous_quote = quote;
	}
	else if (*quote_state == IN && quote == previous_quote)
	{
		*quote_state = OUT;
		previous_quote = 0;
	}
	return ;
}
