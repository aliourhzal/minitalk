/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:12:55 by aourhzal          #+#    #+#             */
/*   Updated: 2022/01/15 14:06:54 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	g_i;

static void	get_ascii(char *bcode)
{
	int		dec;
	int		j;
	int		base;
	char	chr;

	dec = 0;
	base = 128;
	j = 0;
	while (j < 9)
	{
		dec += (bcode[j] - 48) * base;
		j++;
		base = base / 2;
	}
	chr = dec;
	write(1, &chr, 1);
}

static void	hundler(int sig, struct __siginfo *info, void *context)
{
	char		bcode[8];
	static int	pid;

	(void)context;
	if (pid == 0)
		pid = info->si_pid;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		g_i = 0;
	}
	if (sig == SIGUSR1)
		bcode[g_i++] = '0';
	else
		bcode[g_i++] = '1';
	if (g_i == 8)
	{
		get_ascii(bcode);
		kill(pid, SIGUSR1);
		g_i = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	switches;

	(void)av;
	if (ac == 1)
	{
		switches.sa_sigaction = hundler;
		switches.sa_flags = SA_SIGINFO;
		if (sigaction(SIGUSR1, &switches, NULL) != 0)
			write(1, "signal error\n", 13);
		if (sigaction(SIGUSR2, &switches, NULL) != 0)
			write(1, "signal error\n", 13);
		ft_putnbr(getpid());
		write(1, "\n", 1);
		while (1)
			pause();
	}
	else
		write(1, "server take no arguments\n", 25);
}
