/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 10:51:36 by asebrech          #+#    #+#             */
/*   Updated: 2021/06/28 17:56:02 by asebrech         ###   ########.fr       */
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
		str = ft_decimal(av[2][i]);
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
		free(str);
		i++;
	}
}

static void	ft_alldigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_putstr_fd("Second argument is not a PID\n", 2);
			exit(1);
		}
		i++;
	}
}

int	main (int ac, char **av)
{
	pid_t	pid;

	pid = 0;
	if (ac == 3)
	{
		ft_alldigit(av[1]);
		pid = ft_atoi(av[1]);
		ft_convert(av, pid);
	}
	else if (ac > 3)
		ft_putstr_fd("Too many arguments\n", 2);
	else if (ac < 3 && ac != 1)
		ft_putstr_fd("Too few arguments\n", 2);
	return (0);
}
