/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 22:06:39 by maeferre          #+#    #+#             */
/*   Updated: 2024/02/14 19:20:39 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putstr(char *s)
{
	int	length;

	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	length = ft_strlen(s);
	if (length >= 0)
		if (write(1, s, length) == -1)
			return (-1);
	return (length);
}
