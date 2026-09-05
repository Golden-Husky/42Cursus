/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsangjan <rsangjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 00:04:54 by rsangjan          #+#    #+#             */
/*   Updated: 2026/09/01 01:45:26 by rsangjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;
	size_t	total;

	if (count != 0 && size > ((size_t)-1) / count)
		return (NULL);
	total = size * count;
	temp = malloc(total);
	if (!temp)
		return (NULL);
	ft_bzero(temp, total);
	return (temp);
}
