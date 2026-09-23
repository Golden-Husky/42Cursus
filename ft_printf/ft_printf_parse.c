/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsangjan <rsangjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 22:58:25 by rsangjan          #+#    #+#             */
/*   Updated: 2026/09/20 23:28:21 by rsangjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static int	ft_is_flag(char c)
{
	return (c == '-' || c == '0' || c == '#'
		|| c == '+' || c == ' ');
}

static int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static void	ft_set_flag(t_format *format, char c)
{
	if (c == '-')
		format->minus = 1;
	else if (c == '0')
		format->zero = 1;
	else if (c == '#')
		format->hash = 1;
	else if (c == '+')
		format->plus = 1;
	else if (c == ' ')
		format->space = 1;
}

int	ft_parse_flags(const char *str, int idx, t_format *format)
{
	while (ft_is_flag(str[idx]))
	{
		ft_set_flag(format, str[idx]);
		idx++;
	}
	return (idx);
}

int	ft_parse_width(const char *str, int idx, t_format *format)
{
	int	digit;

	while (ft_is_digit(str[idx]))
	{
		digit = str[idx] - '0';
		if (format->width > (INT_MAX - digit) / 10)
			return (-1);
		format->width = format->width * 10 + digit;
		idx++;
	}
	return (idx);
}
