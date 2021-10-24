/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraynald <eraynald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:37:57 by eraynald          #+#    #+#             */
/*   Updated: 2021/10/19 21:25:06 by eraynald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	compare_set(const char s, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (s == set[i])
			return (0);
		i++;
	}
	return (1);
}

static char	*in_char_str(char *p, size_t size_sn,
		size_t size_sk, char const *s1)
{
	size_t	i;

	i = 0;
	while (size_sn + i <= size_sk)
	{
		p[i] = s1[size_sn + i];
		i++;
	}
	p[size_sk - size_sn + 1] = '\0';
	return (p);
}

static int	size_sk_schet(char const *s1)
{
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

static int	size_sn_schet(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (compare_set(s1[i], set))
			break ;
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	size_sn;
	size_t	size_sk;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0' )
	{
		p = malloc(sizeof(char));
		p[0] = '\0';
		return (p);
	}
	size_sn = size_sn_schet(s1, set);
	size_sk = size_sk_schet(s1);
	while (s1[--size_sk] && size_sk > size_sn)
		if (compare_set(s1[size_sk], set))
			break ;
	p = malloc(sizeof(char) * (size_sk - size_sn + 2));
	if (p == NULL)
		return (NULL);
	return (in_char_str(p, size_sn, size_sk, s1));
}
