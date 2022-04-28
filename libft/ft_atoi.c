/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:05:03 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/28 13:09:05 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == 32)
		return (1);
	return (0);
}

static void	handle_sign(const char *str, long long *sign, int *i)
{
	if (str[*i] == '-')
	{
		(*sign) = -(*sign);
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
}

static long long of_before_conv(const char *str, unsigned long long nbr, long long sign)
{
	if (ft_strlen(str) > 19 && sign == -1)
	{
		if (str[19] == '8')
			return (0);
		else if (str[20] == '9' || nbr > 922337203685477580)
			return (OVERFLOW);
	}
	if (ft_strlen(str) > 19 && sign == 1)
		return (OVERFLOW);
	return (1);
}

static long long of_after_conv(unsigned long long nbr, long long sign)
{
	if (nbr > LLONG_MAX && sign == 1)
		return (OVERFLOW);
	if (nbr > LLONG_MAX && sign == -1)
		return (OVERFLOW);
	return (NO);
}

long long	ft_atoi(const char *str)
{
	unsigned long long	nbr;
	long long			sign;
	int					i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	handle_sign(str, &sign, &i);
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + str[i] - '0';
		i++;
		if (of_before_conv(str, nbr, sign) == OVERFLOW)
			return (OVERFLOW);
		if (of_before_conv(str, nbr, sign) == 0)
			return (0);
	}
	if (of_after_conv(nbr, sign) == OVERFLOW)
		return (OVERFLOW);
	return (nbr * sign);
}
