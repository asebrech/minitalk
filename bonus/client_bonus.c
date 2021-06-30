/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:40:54 by asebrech          #+#    #+#             */
/*   Updated: 2021/06/30 09:40:56 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static char	*ft_binary(unsigned char c)
{
	int		i;
	char	*octet;

	i = 0;
	octet = malloc(sizeof(unsigned char) * 8);
	if (!octet)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	while (i < 8)
	{
		if (c % 2)
			octet[7 - i] = '1';
		else
			octet[7 - i] = '0';
		c /= 2;
		i++;
	}
	return (octet);
}

static void	ft_end(pid_t pid)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_binary('\0');
	while (str[i])
	{
		if (str[i] == '0')
			kill(pid, SIGUSR1);
		else if (str[i] == '1')
			kill(pid, SIGUSR2);
		usleep(150);
		i++;
	}
	free(str);
}

static void	ft_convert(char **av, pid_t pid)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (av[2][i])
	{
		str = ft_binary(av[2][i]);
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
	ft_end(pid);
}

static void	reception(int sign)
{
	if (sign == SIGUSR1)
		ft_putstr_fd("MESSAGE RECEIVED\n", 1);
}

int	main (int ac, char **av)
{
	pid_t	pid;
	int		i;

	pid = 0;
	i = 0;
	signal(SIGUSR1, &reception);
	if (ac == 3)
	{
		while (av[1][i])
		{
			if (!ft_isdigit(av[1][i]))
			{
				ft_putstr_fd("Second argument is not valid\n", 1);
				exit(1);
			}
			i++;
		}
		pid = ft_atoi(av[1]);
		ft_convert(av, pid);
	}
	else if (ac > 3)
		ft_putstr_fd("Too many arguments\n", 1);
	else if (ac < 3 && ac != 1)
		ft_putstr_fd("Too few arguments\n", 1);
	return (0);
}
