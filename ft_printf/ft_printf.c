/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsangjan <rsangjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 00:35:08 by rsangjan          #+#    #+#             */
/*   Updated: 2026/09/23 13:51:27 by rsangjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_conversion(const char *str, int *idx, va_list *args)
{
	t_format	format;

	*idx = ft_parse_format(str, *idx + 1, &format);
	if (*idx == -1)
		return (-1);
	if (format.specifier == 'd' || format.specifier == 'i')
		return (ft_printf_decimal_bonus(va_arg(*args, int), &format));
	if (format.specifier == 'u')
		return (ft_printf_unsigned_bonus(va_arg(*args, unsigned int), &format));
	return (ft_handle_format(format.specifier, args));
}

static int	ft_print_all(const char *format, va_list *args)
{
	int	idx;
	int	count;
	int	printed;

	idx = 0;
	count = 0;
	while (format[idx] != '\0')
	{
		if (format[idx] == '%')
			printed = ft_print_conversion(format, &idx, args);
		else
			printed = ft_putchar(format[idx]);
		if (printed < 0)
			return (-1);
		count += printed;
		idx++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	count = ft_print_all(format, &args);
	va_end(args);
	return (count);
}
