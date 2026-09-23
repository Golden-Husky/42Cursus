/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsangjan <rsangjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 23:26:47 by rsangjan          #+#    #+#             */
/*   Updated: 2026/09/23 13:09:48 by rsangjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_format
{
	int		minus;
	int		zero;
	int		hash;
	int		plus;
	int		space;
	int		width;
	int		precision;
	char	specifier;
}	t_format;

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(long n);
int		ft_putunsigned(unsigned int n);
int		ft_puthex(unsigned long n, const char *base);
int		ft_putptr(void *ptr);
int		ft_handle_format(char format, va_list *args);
void	ft_init_format(t_format *format);
int		ft_parse_flags(const char *str, int idx, t_format *format);
int		ft_parse_width(const char *str, int idx, t_format *format);
int		ft_parse_precision(const char *str, int idx, t_format *format);
int		ft_parse_format(const char *str, int idx, t_format *format);
int		ft_count_digit(unsigned long value, int base);
int		ft_put_padding(char c, int padding);
int		ft_printf_char_bonus(int c, const t_format *format);
int		ft_printf_string_bonus(const char *str, const t_format *format);
int		ft_printf_decimal_bonus(int n, const t_format *format);
char	ft_decimal_sign(int n, const t_format *format);
int		ft_putnbr_precision_bonus(int n, const t_format *format);
int		ft_printf_unsigned_bonus(unsigned int n, const t_format *format);

#endif
