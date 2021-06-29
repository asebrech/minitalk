/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 10:55:42 by asebrech          #+#    #+#             */
/*   Updated: 2021/06/29 16:52:54 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int ft_decimal(int nbr)
{
    int deci_nbr;
    int ret;
    int base;

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
	static int	j = 0;
	static char	c[8];
	static char	str[10000];
	int	nb;

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
		nb = ft_atoi(c);
		nb = ft_decimal(nb);
		str[j] = (unsigned char)nb;
		str[j + 1] = '\0';
		j++;
		i = 0;
		ft_putstr_fd(str, 1);
		j = 0;
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

int	main()
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
	while(1)
		;
	return (0);
}
