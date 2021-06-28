/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:43:49 by asebrech          #+#    #+#             */
/*   Updated: 2021/06/28 16:52:26 by asebrech         ###   ########.fr       */
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

static int	ft_nbrlen(long int nbr, int len_base)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr != 0)
	{
		nbr /= len_base;
		len++;
	}
	return (len);
}

static void	ft_alloc(long int nbr, char *base, int len_nbr, char *str)
{
	int	len_base;

	len_base = ft_strlen(base);
	if (nbr == 0)
		str[0] = '0';
	else if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr != 0)
	{
		len_nbr--;
		str[len_nbr] = base[nbr % len_base];
		nbr /= len_base;
	}
}

char	*ft_itoa_base(long int nbr, char *base)
{
	char	*str;
	int		len_nbr;
	int		len_base;

	len_base = ft_strlen(base);
	len_nbr = ft_nbrlen(nbr, len_base);
	str = malloc(sizeof(char) * len_nbr + 1);
	if (!str)
		return (NULL);
	str[len_nbr] = '\0';
	ft_alloc(nbr, base, len_nbr, str);
	return (str);
}
