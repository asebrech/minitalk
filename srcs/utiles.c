/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:43:49 by asebrech          #+#    #+#             */
/*   Updated: 2021/06/28 17:54:29 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_binary(int nbr)
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

char	*ft_decimal(char c)
{
	int		i;
	char	*octet;
	i = 0;
	octet = malloc(sizeof(char) * 8);
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
