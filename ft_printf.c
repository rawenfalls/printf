/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraynald <eraynald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:51:36 by eraynald          #+#    #+#             */
/*   Updated: 2021/10/24 20:16:39 by eraynald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static int	ft_putnbr_fd_unsigned(unsigned int n, int fd)
{
	char		e;
	unsigned int	i;
	unsigned int	num;
	int	l;

	if (n == 0)
		write(fd, "0", 1);
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	num = n;
	i = 0;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	l=i;
	while (i > 0)
	{
		num = step_meu(i);
		e = n / num + '0';
		write(fd, &e, 1);
		n %= num;
		i--;
	}
	return(l);
}

int print_numberx(long int num, int fd, char p, int len)
{
	char	*x;
	char	e;

	x="0123456789abcdef";
	if ((int)num == 0 && len == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (num == 0)
		return (len);
	if (num < 0)
		num = 9223372036854775807+num+1;
	if (p == 'X' && num % 16 > 9)
		e = x[num%16] - 32;
	else
		e = x[num%16];
	num = num / 16;
	if (len == 8)
	{
		return (len);
	}
	len+=1;
	len = print_numberx(num, fd, p, len);
	
	write(fd, &e, 1);
	return(len);
}

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

int	ft_putnbr_fd1(int n, int fd)
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
	l=i;
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

int	ft_printf(const char *fmt, ...)
{
	size_t	schet;
	va_list	arg;
	int	i;
	int	num;
	unsigned int	unsigned_num;
	long int	long_num;
	char	e;
	char	*p;
	schet = 0;
	if (!fmt)
		return(-1);
	va_start(arg, fmt);
	i = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == 's')
			{
				p = va_arg(arg, char *);
				if (!p)
				{
					write(1,"(null)",6);
					schet+=6;
				}
				else
				{
					while (*p)
					{
						e=*p;
						write(1, &*p,1);
						p++;
						schet++;
					}
				}
			}
			else if(*fmt == 'c')
			{
				e=(char)va_arg(arg, int);
				write(1,&e,1);
				schet++;
			}
			else if(*fmt == 'd' || *fmt == 'i')
			{
				num = va_arg(arg, int);
				if (num < 0)
					schet++;
				if (num == -2147483648)
				{
					schet+=10;
					ft_putnbr_fd1(num, 1);
				}
				else
					schet += ft_putnbr_fd1(num, 1);
			}
			else if(*fmt == 'u')
			{
				unsigned_num = va_arg(arg, unsigned int);
				schet += ft_putnbr_fd_unsigned(unsigned_num, 1);
			}
			else if(*fmt == 'x' || *fmt == 'X')
			{
				long_num = va_arg(arg,long int);
				schet += print_numberx(long_num, 1, *fmt, 0);
			}
			else if(*fmt == '%')
			{
				write(1,"%",1);
				schet++;
			}
		}
		else
		{
			e=*fmt;
			write(1,&e,1);
			schet++;
		}
		fmt++;
	}
	va_end(arg);
	return (schet);
}

// int main(int a, char **b)
// {
// 	char	*p;
// 	if (a > 1)
// 	{
// 		b++; 
// 		p = *b;
// 		while (*p != '\0')
// 		{
// 			printf("%c = ",*p);
// 			ft_printf("%c",*p);
// 			p++;
// 		}
// 	}
// 	else
// 	{
// 		//printf(" |%d|", printf(" %x %x %x %x %x %x %x", __INT_MAX__, -__INT_MAX__ -1, __LONG_MAX__, -__LONG_MAX__ -1L, __LONG_MAX__ *2UL+1UL, 0, -42));
// 		// e='0'+0B0010;
// 		// write(1,&e,1);
// 		printf(" |%u|", printf("%d", 4294967294));
// 		printf(" |%u|=my", ft_printf("%d\n", 4294967294)-1);
// 	}
// 	return 0;
// }