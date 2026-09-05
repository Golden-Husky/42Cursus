/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsangjan <rsangjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 17:10:27 by rsangjan          #+#    #+#             */
/*   Updated: 2026/09/01 19:08:24 by rsangjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_all(char **res, size_t i)
{
	while (i > 0)
	{
		i--;
		free(res[i]);
	}
	free(res);
	return (NULL);
}

static char	**fill_split(char **res, const char *str, char c)
{
	size_t	start;
	size_t	end;
	size_t	i;

	end = 0;
	i = 0;
	while (str[end])
	{
		while (str[end] && str[end] == c)
			end++;
		start = end;
		while (str[end] && str[end] != c)
			end++;
		if (end > start)
		{
			res[i] = ft_substr(str, start, end - start);
			if (!res[i])
				return (free_all(res, i));
			i++;
		}
	}
	res[i] = NULL;
	return (res);
}

static size_t	count_words(const char *str, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

char	**ft_split(const char *str, char c)
{
	char	**res;

	if (!str)
		return (NULL);
	res = malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!res)
		return (NULL);
	return (fill_split(res, str, c));
}
