/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraynald <eraynald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:35:54 by eraynald          #+#    #+#             */
/*   Updated: 2021/10/20 14:16:14 by eraynald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	how_much_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (i);
}

static char	**cycle_len(char const *s, char c, char	**p)
{
	size_t	i;
	size_t	str_count;
	char	*str;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		str = (char *)s;
		str_count = 0;
		while ((*s != c) && *s)
		{
			str_count++;
			s++;
		}
		if (*(s - 1) != c)
			p[i++] = ft_substr(str, 0, str_count);
	}
	p[i] = NULL;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;

	if (!s)
		return (NULL);
	p = (char **)malloc(sizeof(char *) * (how_much_len(s, c) + 1));
	if (!p)
		return (NULL);
	return (cycle_len(s, c, p));
}
