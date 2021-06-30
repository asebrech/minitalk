/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:41:07 by asebrech          #+#    #+#             */
/*   Updated: 2021/06/30 09:41:10 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	ft_decimal(int nbr)
{
	int	deci_nbr;
	int	ret;
	int	base;

	deci_nbr = 0;
	base = 1;
	while (nbr > 0)
	{
		ret = nbr % 10;
		deci_nbr = deci_nbr + ret * base;
		nbr = nbr / 10;
		base = base * 2;
	}
	return (deci_nbr);
}

static void	fill(int sig, siginfo_t *info, void *context)
{
	static int	i = 0;
	static char	c[8];
	int			nb;

	context = NULL;
	nb = 0;
	if (sig == SIGUSR1)
		c[i] = '0';
	else if (sig == SIGUSR2)
		c[i] = '1';
	i++;
	if (i == 8)
	{
		c[i] = '\0';
		i = 0;
		nb = ft_atoi(c);
		nb = ft_decimal(nb);
		ft_putchar_fd((unsigned char)nb, 1);
		if ((unsigned char)nb == '\0')
			kill(info->si_pid, SIGUSR1);
	}
}

static void	ft_print(void)
{
	ft_putstr_fd("PID = ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_print();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &fill;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
	return (0);
}
