/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraynald <eraynald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:30:15 by eraynald          #+#    #+#             */
/*   Updated: 2021/10/19 19:41:23 by eraynald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_needle(const char *needle)
{
	int		siz;

	siz = 0;
	while (needle[siz] != '\0')
		siz++;
	return (siz);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		e;
	int		siz;

	i = 0;
	siz = len_needle(needle);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while ((haystack[i] != '\0') && (i < len))
	{
		if (haystack[i] == needle[0])
		{
			e = 0;
			while ((((char *)needle)[e] != '\0') && (i + e < len))
			{
				if (((char *)haystack)[i + e] != ((char *)needle)[e])
					break ;
				if (e + 1 == siz)
					return ((char *)&haystack[i]);
				e++;
			}
		}
		i++;
	}
	return (NULL);
}
