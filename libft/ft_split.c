/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 10:41:45 by asebrech          #+#    #+#             */
/*   Updated: 2021/04/05 11:18:33 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	word_count(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
			count++;
		i++;
	}
	return (count);
}

static unsigned int	word_length(char const *s, char c, unsigned int a)
{
	unsigned int	i;
	unsigned int	length;

	i = 0;
	length = 0;
	while (s[i] == c)
		i++;
	while (a)
	{
		if (s[i] == c && s[i + 1] != c)
			a--;
		i++;
	}
	while (s[i] && s[i] != c)
	{
		length++;
		i++;
	}
	return (length);
}

static char	*cpyword(char const *s, char c, unsigned int a)
{
	char			*word;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	word = (char *)malloc(sizeof(char) * word_length(s, c, a) + 1);
	if (!word)
		return (NULL);
	while (s[i] == c)
		i++;
	while (a)
	{
		if (s[i] == c && s[i + 1] != c)
			a--;
		i++;
	}
	while (s[i] && s[i] != c)
	{
		word[j] = s[i];
		j++;
		i++;
	}
	word[j] = 0;
	return (word);
}

static void	free_tab(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	cases;
	char			**tab;

	if (!s)
		return (NULL);
	cases = word_count(s, c);
	tab = (char **)malloc(sizeof(char *) * (cases + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < cases)
	{
		tab[i] = cpyword(s, c, i);
		if (!tab[i])
		{
			free_tab(tab);
			free(tab);
			return (NULL);
		}
		i++;
	}
	tab[i] = 0;
	return (tab);
}
