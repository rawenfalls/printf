/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraynald <eraynald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:56:29 by eraynald          #+#    #+#             */
/*   Updated: 2021/10/20 00:28:55 by eraynald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*create_newstring(size_t i)
{
	char	*p;

	p = malloc(sizeof(char) * i + 1);
	if (!p)
		return (NULL);
	p[i] = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (size <= start)
		return (create_newstring(0));
	if ((len + start) > size)
		len = size - start;
	p = create_newstring(len);
	if (!p)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = s[i + (size_t)start];
		i++;
	}
	return (p);
}
