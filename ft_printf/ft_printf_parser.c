/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsangjan <rsangjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 00:00:57 by rsangjan          #+#    #+#             */
/*   Updated: 2026/09/21 00:00:58 by rsangjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_format(const char *str, int idx, t_format *format)
{
	ft_init_format(format);
	idx = ft_parse_flags(str, idx, format);
	idx = ft_parse_width(str, idx, format);
	if (idx == -1)
		return (-1);
	idx = ft_parse_precision(str, idx, format);
	if (idx == -1)
		return (-1);
	format->specifier = str[idx];
	return (idx);
}
