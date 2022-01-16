/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:07:28 by aourhzal          #+#    #+#             */
/*   Updated: 2022/01/10 17:16:01 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int				i;
	unsigned long	intv;
	int				sign;

	i = 0;
	intv = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\n' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
		intv = intv * 10 + nptr[i++] - 48;
	if (intv > 4294967295)
	{
		if (sign == -1)
			return (0);
		return (-1);
	}
	return (intv * sign);
}
