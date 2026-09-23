/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal_precision_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsangjan <rsangjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 15:54:38 by rsangjan          #+#    #+#             */
/*   Updated: 2026/09/22 15:56:49 by rsangjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_precision_bonus(int n, const t_format *format)
{
	long	value;
	int		digits;
	int		zeros;
	int		count_real;
	char	sign;

	value = n;
	count_real = 0;
	sign = ft_decimal_sign(n, format);
	if (sign != '\0')
		count_real += ft_putchar(sign);
	if (value < 0)
		value = -value;
	digits = ft_count_digit(value, 10);
	zeros = 0;
	if (format->precision > digits)
		zeros = format->precision - digits;
	if (format->zero == 1 && format->minus == 0 && format->precision < 0)
		zeros = format->width - digits - (sign != '\0');
	count_real += ft_put_padding('0', zeros);
	if (value != 0 || format->precision != 0)
		count_real += ft_putnbr(value);
	return (count_real);
}
