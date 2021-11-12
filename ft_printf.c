/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraynald <eraynald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:51:36 by eraynald          #+#    #+#             */
/*   Updated: 2021/10/25 21:37:56 by eraynald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_numberx(unsigned int num, char p, int len)
{
	char	*x;
	char	e;

	x = "0123456789abcdef";
	if ((int)num == 0 && len == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if ((int)num == 0)
		return (len);
	if (num < 0)
		num = 9223372036854775807 + num + 1;
	if (p == 'X' && num % 16 > 9)
		e = x[num % 16] - 32;
	else
		e = x[num % 16];
	num = num / 16;
	if (len == 8)
		return (len);
	len += 1;
	len = print_numberx(num, p, len);
	write(1, &e, 1);
	return (len);
}

static int	print_numberp(long unsigned int num, char p, int len)
{
	char	*x;
	char	e;

	x = "0123456789abcdef";
	if (len == 2)
		write(1, "0x", 2);
	if (num == 0 && len == 2)
		return (write(1, "0", 1) + 2);
	if (num == 0)
		return (len);
	e = x[num % 16];
	num = num / 16;
	if (len == 18)
		return (len);
	len += 1;
	len = print_numberp(num, p, len);
	write(1, &e, 1);
	return (len);
}

static int	raspred_f(unsigned int num, char p, size_t schet)
{
	if (p == 'u')
		schet += ft_putnbr_fd_unsigned(num, 0);
	else
		schet += print_numberx(num, p, 0);
	return (schet);
}

static int	change_f(const char *fmt, size_t schet, va_list arg, size_t i)
{
	if (fmt[i] == 's')
		schet += write_string(va_arg(arg, char *));
	else if (fmt[i] == 'c')
		schet += write_char((char)(va_arg(arg, int)));
	else if (fmt[i] == 'd' || fmt[i] == 'i')
		schet += write_d_i(va_arg(arg, int), 0);
	else if (fmt[i] == 'x' || fmt[i] == 'X' || fmt[i] == 'u')
		schet += raspred_f(va_arg(arg, unsigned int), fmt[i], 0);
	else if (fmt[i] == 'p')
		schet += print_numberp(va_arg(arg, long unsigned int), fmt[i], 2);
	else if (fmt[i] == '%')
		schet += write(1, "%", 1);
	return (schet);
}

int	ft_printf(const char *fmt, ...)
{
	size_t	schet;
	va_list	arg;
	size_t	i;

	schet = 0;
	i = 0;
	if (!fmt)
		return (-1);
	va_start(arg, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			schet += change_f(fmt, 0, arg, i);
		}
		else
			schet += write(1, &fmt[i], 1);
		i++;
	}
	va_end(arg);
	return (schet);
}
