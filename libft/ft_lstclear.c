/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraynald <eraynald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:34:16 by eraynald          #+#    #+#             */
/*   Updated: 2021/10/20 16:51:39 by eraynald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*e;

	if (lst && del)
	{
		while (*lst)
		{
			e = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = e;
		}
	}
}
