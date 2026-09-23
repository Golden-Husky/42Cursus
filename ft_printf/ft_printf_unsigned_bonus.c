/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsangjan <rsangjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:59:54 by rsangjan          #+#    #+#             */
/*   Updated: 2026/09/23 13:09:45 by rsangjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unsigned_length(unsigned int n, const t_format *format)
{
	int	length;

	length = ft_count_digit(n, 10);
	if (n == 0 && format->precision == 0)
		length = 0;
	if (format->precision > length)
		length = format->precision;
	return (length);
}

static int	ft_putunsigned_bonus(unsigned int n, const t_format *format)
{
	int	digits;
	int	zeros;
	int	count;

	digits = ft_count_digit(n, 10);
	zeros = 0;
	if (format->precision > digits)
		zeros = format->precision - digits;
	if (format->zero == 1 && format->minus == 0 && format->precision < 0)
		zeros = format->width - digits;
	count = ft_put_padding('0', zeros);
	if (n != 0 || format->precision != 0)
		count += ft_putunsigned(n);
	return (count);
}

int	ft_printf_unsigned_bonus(unsigned int n, const t_format *format)
{
	int	length;
	int	count;

	length = ft_unsigned_length(n, format);
	count = 0;
	if (format->minus == 0
		&& (format->zero == 0 || format->precision >= 0))
		count += ft_put_padding(' ', format->width - length);
	count += ft_putunsigned_bonus(n, format);
	if (format->minus == 1)
		count += ft_put_padding(' ', format->width - length);
	return (count);
}
