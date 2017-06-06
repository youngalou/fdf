/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:35:52 by lyoung            #+#    #+#             */
/*   Updated: 2017/03/12 09:51:05 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(const char *s, char c)
{
	int		count;
	int		in_sub;

	count = 0;
	in_sub = 0;
	while (*s)
	{
		if (*s == c && in_sub == 1)
			in_sub = 0;
		if (*s != c && in_sub == 0)
		{
			in_sub = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static int		count_letters(const char *s, char c)
{
	int		count;

	count = 0;
	while (*s && *s != c)
	{
		s++;
		count++;
	}
	return (count);
}

char			**ft_strsplit(const char *s, char c)
{
	int		i;
	int		words;
	char	**tab;

	if (!s || !c)
		return (0);
	i = 0;
	words = count_words(s, c);
	tab = (char**)malloc(sizeof(tab) * words + 1);
	if (!tab)
		return (0);
	while (words--)
	{
		while (*s && *s == c)
			s++;
		tab[i] = ft_strsub(s, 0, count_letters(s, c));
		if (!tab[i])
			return (0);
		s = s + count_letters(s, c);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
