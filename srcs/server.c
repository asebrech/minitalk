/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 10:55:42 by asebrech          #+#    #+#             */
/*   Updated: 2021/06/28 16:32:46 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	fill(int sign)
{
	static int	i = 0;
	static char	str[7];
	int	nb;

	nb = 0;
	if (sign == SIGUSR1)
		str[i] = '0';
	else if (sign == SIGUSR2)
		str[i] = '1';
	i++;
	if (i == 7)
	{
		str[i] = '\0';
		nb = ft_atoi(str);
		nb = ft_binary(nb);
		ft_putchar_fd((char)nb, 1);
		i = 0;
	}
}

int	main()
{
	ft_putstr_fd("PID = ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);

	signal(SIGUSR1, &fill);
	signal(SIGUSR2, &fill);
	while(1)
		;
}
