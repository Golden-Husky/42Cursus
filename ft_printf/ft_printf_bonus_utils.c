/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsangjan <rsangjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 12:39:48 by rsangjan          #+#    #+#             */
/*   Updated: 2026/09/22 12:39:49 by rsangjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_digit(unsigned long value, int base)
{
	int	length;

	length = 1;
	while (value >= (unsigned long)base)
	{
		value /= (unsigned long)base;
		length++;
	}
	return (length);
}

int	ft_put_padding(char c, int padding)
{
	int	count;

	count = 0;
	while (count < padding)
	{
		ft_putchar(c);
		count++;
	}
	return (count);
}
