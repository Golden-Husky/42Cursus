# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsangjan <rsangjan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/20 22:15:54 by rsangjan          #+#    #+#              #
#    Updated: 2026/09/23 13:11:38 by rsangjan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRC = ft_printf.c \
	  ft_printf_utils.c \
	  ft_printf_numbers.c \
	  ft_printf_format.c \
	  ft_printf_bonus.c \
	  ft_printf_parse.c \
	  ft_printf_precision.c \
	  ft_printf_parser.c \
	  ft_printf_bonus_utils.c \
	  ft_printf_char_bonus.c \
	  ft_printf_string_bonus.c \
	  ft_printf_decimal_bonus.c \
	  ft_printf_decimal_precision_bonus.c \
	  ft_printf_unsigned_bonus.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
