/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsangjan <rsangjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 13:22:26 by rsangjan          #+#    #+#             */
/*   Updated: 2026/09/20 16:21:37 by rsangjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	idx;

	if (str == NULL)
		return (ft_putstr("(null)"));
	idx = 0;
	while (str[idx] != '\0')
	{
		ft_putchar(str[idx]);
		idx++;
	}
	return (idx);
}

int	ft_putptr(void *ptr)
{
	int	count;

	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	count = 0;
	ft_putchar('0');
	ft_putchar('x');
	count += 2;
	count += ft_puthex((unsigned long)ptr, "0123456789abcdef");
	return (count);
}
