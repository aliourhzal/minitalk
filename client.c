/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:27:22 by aourhzal          #+#    #+#             */
/*   Updated: 2022/01/15 10:46:14 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft.h"

int	g_index;

static char	*normalize(char *bcode)
{
	int		len;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(bcode);
	str = malloc(9 * sizeof(char));
	while (i < (8 - len))
	{
		str[i] = '0';
		i++;
	}
	while (bcode[j])
		str[i++] = bcode[j++];
	str[i] = 0;
	free(bcode);
	return (str);
}

static char	*convert_char(unsigned char chr)
{
	char	*bcode;
	int		i;

	i = 0;
	bcode = malloc(9 * sizeof(char));
	ft_bzero(bcode, 9);
	ft_putbin(chr, bcode, &i);
	bcode = normalize(bcode);
	return (bcode);
}

static void	send_char(int pid, unsigned char chr)
{
	char	*bcode;
	int		i;

	i = -1;
	bcode = convert_char(chr);
	while (++i < 9)
	{
		if (bcode[i] == '0')
		{
			if (kill(pid, SIGUSR1) != 0)
			{
				write(1, "Invalid PID\n", 12);
				exit(0);
			}
		}
		else if (bcode[i] == '1')
		{
			if (kill(pid, SIGUSR2) != 0)
			{
				write(1, "Invalid PID\n", 12);
				exit(0);
			}
		}
		usleep(800);
	}
}

void	verify(int sig)
{
	(void)sig;
	if (g_index == 0)
	{
		write(1, "signal sent and received successefuly\n", 38);
		g_index++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	signal(SIGUSR1, verify);
	if (ac == 3)
	{
		i = 0;
		pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
			write(1, "Invalid pid\n", 12);
			exit(1);
		}
		while (av[2][i])
		{
			send_char(pid, av[2][i]);
			i++;
			usleep(100);
		}
	}
	else
		write(1, "syntax: ./client PID_SERVER MSG\n", 32);
}
