/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsangjan <rsangjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 22:46:28 by rsangjan          #+#    #+#             */
/*   Updated: 2026/09/20 22:46:30 by rsangjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_format(t_format *format)
{
	format->minus = 0;
	format->zero = 0;
	format->hash = 0;
	format->plus = 0;
	format->space = 0;
	format->width = 0;
	format->precision = -1;
	format->specifier = '\0';
}
