/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsangjan <rsangjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 12:40:06 by rsangjan          #+#    #+#             */
/*   Updated: 2026/09/22 12:40:31 by rsangjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_string_bonus(const char *str, const t_format *format)
{
	int	length;
	int	idx;
	int	count;

	length = 0;
	while (str[length] != '\0'
		&& (format->precision < 0 || length < format->precision))
		length++;
	count = 0;
	if (format->minus == 0)
		count += ft_put_padding(' ', format->width - length);
	idx = 0;
	while (idx < length)
	{
		count += ft_putchar(str[idx]);
		idx++;
	}
	if (format->minus == 1)
		count += ft_put_padding(' ', format->width - length);
	return (count);
}
