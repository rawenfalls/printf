/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraynald <eraynald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:16:52 by eraynald          #+#    #+#             */
/*   Updated: 2021/10/19 19:40:48 by eraynald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_schet(char const *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size1;
	size_t	size2;
	size_t	size3;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	size1 = len_schet(s1);
	size2 = len_schet(s2);
	size3 = 0;
	p = malloc(sizeof(char) * (size1 + size2));
	if (p == NULL)
		return (NULL);
	while (size3 < size1 + size2)
	{
		if (size3 < size1)
			p[size3] = s1[size3];
		else
			p[size3] = s2[size3 - size1];
		size3++;
	}
	p[size3] = '\0';
	return (p);
}
