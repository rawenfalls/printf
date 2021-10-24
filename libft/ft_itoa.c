/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraynald <eraynald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:17:57 by eraynald          #+#    #+#             */
/*   Updated: 2021/10/19 19:39:29 by eraynald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	schet_len(int n)
{
	int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		len;
	int		negativ;

	if (n < 0)
		negativ = -1;
	else
		negativ = 1;
	len = schet_len(n);
	p = (char *)malloc(sizeof(char) * len + 1);
	if (p == NULL)
		return (0);
	p[len] = '\0';
	while (--len >= 0)
	{
		if (n < 0)
			p[len] = n % 10 * -1 + '0';
		else
			p[len] = n % 10 + '0';
		n /= 10;
	}
	if (negativ == -1)
		p[0] = '-';
	return (p);
}
