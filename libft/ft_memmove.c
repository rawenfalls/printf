/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraynald <eraynald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:42:16 by eraynald          #+#    #+#             */
/*   Updated: 2021/10/06 21:51:14 by eraynald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst1;
	const char	*src1;

	if ((dst == NULL) && (src == NULL))
		return (NULL);
	i = 0;
	dst1 = (char *)dst;
	src1 = (const char *)src;
	if (dst1 < src1)
	{
		while (i < n)
		{
			dst1[i] = src1[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i--)
			dst1[i] = src1[i];
	}
	return (dst);
}
