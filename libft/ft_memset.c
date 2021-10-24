/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraynald <eraynald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:42:20 by eraynald          #+#    #+#             */
/*   Updated: 2021/10/19 19:39:51 by eraynald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *arr, int simb, size_t col)
{
	size_t	i;
	char	*c;

	i = 0;
	c = arr;
	while (i < col)
		c[i++] = simb;
	return (c);
}
