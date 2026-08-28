/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsangjan <rsangjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 22:16:36 by rsangjan          #+#    #+#             */
/*   Updated: 2026/08/27 22:50:38 by rsangjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;
	size_t	j;

	src_len = ft_strlen(src);
	dest_len = 0;
	while (dest[dest_len] != '\0' && dest_len < destsize)
		dest_len++;
	if (destsize <= dest_len)
		return (dest_len + src_len);
	i = dest_len;
	j = 0;
	while (src[j] != '\0' && i < destsize - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (src_len + dest_len);
}
