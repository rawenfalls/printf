/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_dop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraynald <eraynald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:31:41 by eraynald          #+#    #+#             */
/*   Updated: 2021/10/25 21:22:05 by eraynald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	step_me(int i)
{
	int	e;
	int	stp;

	e = i;
	stp = 1;
	while (--e > 0)
		stp *= 10;
	return (stp);
}

static int	check_n(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		n = 0;
	}
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	return (n);
}

static int	ft_putnbr_fd1(int n, int fd)
{
	char	e;
	int		i;
	int		num;
	int		l;

	n = check_n(n, fd);
	if (n == 0)
		return (1);
	num = n;
	i = 0;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	l = i;
	while (i > 0)
	{
		num = step_me(i);
		e = n / num + '0';
		write(fd, &e, 1);
		n %= num;
		i--;
	}
	return (l);
}

int	write_d_i(int num, size_t schet)
{
	if (num < 0)
		schet++;
	if (num == -2147483648)
	{
		schet += 10;
		ft_putnbr_fd1(num, 1);
	}
	else
		schet += ft_putnbr_fd1(num, 1);
	return (schet);
}

int	write_char(char p)
{
	write (1, &p, 1);
	return (1);
}
