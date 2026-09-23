/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsangjan <rsangjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 16:56:32 by rsangjan          #+#    #+#             */
/*   Updated: 2026/09/22 16:56:42 by rsangjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_decimal_sign(int n, const t_format *format)
{
	if (n < 0)
		return ('-');
	if (format->plus == 1)
		return ('+');
	if (format->space == 1)
		return (' ');
	return ('\0');
}

static int	ft_decimal_length(int n, const t_format *format)
{
	long	value;
	int		length;

	value = n;
	if (value < 0)
		value = -value;
	length = ft_count_digit(value, 10);
	if (format->precision > length)
		length = format->precision;
	if (n == 0 && format->precision == 0)
		length = 0;
	if (ft_decimal_sign(n, format) != '\0')
		length++;
	return (length);
}

int	ft_printf_decimal_bonus(int n, const t_format *format)
{
	int		length;
	int		count_real;

	length = ft_decimal_length(n, format);
	count_real = 0;
	if (format->minus == 0
		&& (format->zero == 0 || format->precision >= 0))
		count_real += ft_put_padding(' ', format->width - length);
	count_real += ft_putnbr_precision_bonus(n, format);
	if (format->minus == 1)
		count_real += ft_put_padding(' ', format->width - length);
	return (count_real);
}
