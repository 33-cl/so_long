/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:08:03 by maeferre          #+#    #+#             */
/*   Updated: 2024/02/14 21:13:56 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	ft_putchar(int c)
{
	if (!write(1, &c, 1))
		return (false);
	return (true);
}

bool	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		if (!ft_putstr("-2147483648"))
			return (false);
	}
	else
	{
		if (n < 0)
		{
			n = -n;
			if (!ft_putchar('-'))
				return (false);
		}
		if (n < 10 && n >= 0)
		{
			if (!ft_putchar(n + '0'))
				return (false);
		}
		else
		{
			if (!ft_putnbr(n / 10) || !ft_putnbr(n % 10))
				return (false);
		}
	}
	return (true);
}
