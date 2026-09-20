/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsangjan <rsangjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 14:01:54 by rsangjan          #+#    #+#             */
/*   Updated: 2026/09/20 14:02:34 by rsangjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_char(char format, va_list *args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (format == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (format == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

static int	ft_handle_int(char format, va_list *args)
{
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (format == 'u')
		return (ft_putunsigned(va_arg(*args, unsigned int)));
	if (format == 'x')
		return (ft_puthex(va_arg(*args, unsigned int), "0123456789abcdef"));
	if (format == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	return (0);
}

int	ft_handle_format(char format, va_list *args)
{
	if (format == 'c' || format == 's' || format == 'p' || format == '%')
		return (ft_handle_char(format, args));
	return (ft_handle_int(format, args));
}
