/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 09:38:34 by asebrech          #+#    #+#             */
/*   Updated: 2021/03/30 16:56:10 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(dst);
	i = 0;
	if (dstsize > 0)
	{
		while ((len + i) < (dstsize - 1) && src[i])
		{
			dst[len + i] = src[i];
			i++;
		}
		dst[len + i] = '\0';
	}
	if (len > dstsize)
		return (ft_strlen(src) + dstsize);
	return (ft_strlen(src) + len);
}
