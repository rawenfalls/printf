/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraynald <eraynald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:06:13 by eraynald          #+#    #+#             */
/*   Updated: 2021/10/07 18:34:55 by eraynald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	size;

	size = 0;
	while (s1[size] != '\0')
		size++;
	p = malloc(sizeof(char) * size + 1);
	if (p == NULL)
		return (NULL);
	size = 0;
	while (s1[size] != 0)
	{
		p[size] = s1[size];
		size++;
	}
	p[size] = '\0';
	return (p);
}
