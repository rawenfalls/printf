/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraynald <eraynald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:38:25 by eraynald          #+#    #+#             */
/*   Updated: 2021/10/25 21:41:43 by eraynald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_printf(const char *fmt, ...);
int	write_string(char *p);
int	write_d_i(int num, size_t schet);
int	ft_putnbr_fd_unsigned(unsigned int n, size_t schet);
int	write_char(char p);

#endif
