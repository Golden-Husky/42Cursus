/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsangjan <rsangjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 15:48:57 by rsangjan          #+#    #+#             */
/*   Updated: 2026/09/05 16:13:29 by rsangjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *n)
{
	t_list	*last;

	if (!lst || !n)
		return ;
	if (!*lst)
	{
		*lst = n;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = n;
}
