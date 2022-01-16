/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 09:54:55 by aourhzal          #+#    #+#             */
/*   Updated: 2022/01/15 10:19:43 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbin(int nbr, char *bcode, int *i)
{
	char	bin[2];

	bin[0] = '0';
	bin[1] = '1';
	if (nbr >= 2)
	{
		ft_putbin(nbr / 2, bcode, i);
		ft_putbin(nbr % 2, bcode, i);
	}
	else
	{
		bcode[*i] = bin[nbr];
		*i += 1;
	}
}
