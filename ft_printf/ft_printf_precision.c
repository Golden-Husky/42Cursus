/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsangjan <rsangjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 23:50:21 by rsangjan          #+#    #+#             */
/*   Updated: 2026/09/20 23:58:32 by rsangjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_parse_precision(const char *str, int idx, t_format *format)
{
	int	digit;

	if (str[idx] != '.')
		return (idx);
	format->precision = 0;
	idx++;
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		digit = str[idx] - '0';
		if (format->precision > (INT_MAX - digit) / 10)
			return (-1);
		format->precision = format->precision * 10 + digit;
		idx++;
	}
	return (idx);
}
