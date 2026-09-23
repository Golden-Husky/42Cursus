/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsangjan <rsangjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 12:39:58 by rsangjan          #+#    #+#             */
/*   Updated: 2026/09/22 12:39:59 by rsangjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char_bonus(int c, const t_format *format)
{
	int	padding;
	int	count;

	padding = 0;
	if (format->width > 1)
		padding = format->width - 1;
	count = 0;
	if (format->minus == 0)
		count += ft_put_padding(' ', padding);
	count += ft_putchar(c);
	if (format->minus == 1)
		count += ft_put_padding(' ', padding);
	return (count);
}
