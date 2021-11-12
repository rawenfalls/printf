/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_dop2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraynald <eraynald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:57:07 by eraynald          #+#    #+#             */
/*   Updated: 2021/10/25 21:22:02 by eraynald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_string(char *p)
{
	size_t	schet;

	schet = 0;
	if (!p)
	{
		write (1, "(null)", 6);
		schet += 6;
	}
	else
	{
		while (*p)
		{
			write (1, &*p, 1);
			p++;
			schet++;
		}
	}
	return (schet);
}

static int	step_meu(int i)
{
	unsigned int	e;
	unsigned int	stp;

	e = i;
	stp = 1;
	while (--e > 0)
		stp *= 10;
	return (stp);
}

int	ft_putnbr_fd_unsigned(unsigned int n, size_t schet)
{
	char			e;
	unsigned int	i;
	unsigned int	num;

	if (n == 0)
		return (write(1, "0", 1));
	if (n < 0)
		n *= -1;
	num = n;
	i = 0;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	schet = i;
	while (i > 0)
	{
		num = step_meu(i);
		e = n / num + '0';
		write(1, &e, 1);
		n %= num;
		i--;
	}
	return (schet);
}
