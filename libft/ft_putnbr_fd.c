/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraynald <eraynald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:42:17 by eraynald          #+#    #+#             */
/*   Updated: 2021/10/19 19:40:10 by eraynald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void	ft_putnbr_fd(int n, int fd)
{
	char	e;
	int		i;
	int		num;

	n = check_n(n, fd);
	if (n == 0)
		return ;
	num = n;
	i = 0;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	while (i > 0)
	{
		num = step_me(i);
		e = n / num + '0';
		write(fd, &e, 1);
		n %= num;
		i--;
	}
}
