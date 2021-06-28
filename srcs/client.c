/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 10:51:36 by asebrech          #+#    #+#             */
/*   Updated: 2021/06/28 16:36:24 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_convert(char **av, pid_t pid)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (av[2][i])
	{
		str = ft_itoa_base((long  int)av[2][i], "01");
		if (ft_strlen(str) == 6)
			kill(pid, SIGUSR1);
		j = 0;
		while (str[j])
		{
			if (str[j] == '0')
				kill(pid, SIGUSR1);
			else if (str[j] == '1')
				kill(pid, SIGUSR2);
			usleep(150);
			j++;
		}
		ft_putstr_fd(str, 1);
		free(str);
		i++;
	}
}
int	main (int ac, char **av)
{
	pid_t	pid;

	pid = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		ft_convert(av, pid);
	}
}
