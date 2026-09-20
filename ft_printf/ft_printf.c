/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsangjan <rsangjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 00:35:08 by rsangjan          #+#    #+#             */
/*   Updated: 2026/09/20 14:08:49 by rsangjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		idx;
	int		count;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	idx = 0;
	count = 0;
	while (format[idx] != '\0')
	{
		if (format[idx] == '%')
			count += ft_handle_format(format[++idx], &args);
		else
			count += ft_putchar(format[idx]);
		idx++;
	}
	va_end(args);
	return (count);
}
