/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:14:52 by aourhzal          #+#    #+#             */
/*   Updated: 2022/01/15 14:08:45 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

int		ft_atoi(const char *nptr);
void	ft_putnbr(int n);
int		ft_strlen(char *str);
void	ft_putbin(int nbr, char *bcode, int *i);
void	ft_bzero(void *s, int n);

#endif