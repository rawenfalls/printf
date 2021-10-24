/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraynald <eraynald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:02:30 by eraynald          #+#    #+#             */
/*   Updated: 2021/10/19 19:38:46 by eraynald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_construct(int i, int is_negativ, const char *str)
{
	unsigned int	num_f;

	num_f = 0;
	while (str[++i] != '\0')
	{
		if (num_f > 2147483647 && is_negativ > 0)
			return (-1);
		else if (num_f > 2147483648 && is_negativ < 0)
			return (0);
		else if ((str[i] >= 48) && (str[i] <= 57))
			num_f = num_f * 10 + (((char *)str)[i] - 48);
		else
			break ;
	}
	return ((int)(is_negativ * num_f));
}

int	ft_atoi(const char *str)
{
	int	is_negativ;
	int	i;

	i = -1;
	is_negativ = 1;
	while (str[++i] != '\0')
	{
		if ((str[i] == '-') || (str[i] == '+'))
		{
			if (((char *)str)[i] == '-')
				is_negativ = -1;
			break ;
		}
		else if ((str[i] >= 48) && (str[i] <= 57))
		{
			i--;
			break ;
		}
		else if ((str[i] >= 1) && (str[i] <= 32) && (str[i] != 27))
			continue ;
		else
			return (0);
	}
	return (num_construct(i, is_negativ, str));
}
