# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mblood <mblood@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/11 14:24:47 by mblood            #+#    #+#              #
#    Updated: 2020/07/28 21:48:50 by mblood           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = ft_printf.c ft_check_format.c ft_hexadecimal_notation.c ft_new_conversions.c  ft_parser.c\
		types/ft_int_type.c types/ft_char_type.c types/ft_string_type.c types/ft_unsigned_int_type.c\
		types/ft_x_type.c types/ft_pointer_type.c ft_print_percent.c
			
SOURCES_LIBFT = libft/ft_memset.c libft/ft_strlen.c libft/ft_strlcpy_ch.c \
				libft/ft_atoi.c libft/ft_isdigit.c libft/ft_isalpha.c libft/ft_itoa.c \
				libft/ft_itoa_unsigned.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c \
				libft/ft_putnbr_fd.c libft/ft_abs.c libft/ft_nblen.c

OBJ = $(SOURCES:.c=.o)
DIR_LIBFT = libft/
OBJ_LIBFT = $(SOURCES_LIBFT:.c=.o)

COMPILER = gcc -c -Wall -Wextra -Werror

HEADER = ft_printf.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_LIBFT)
	ar rcs $(NAME) $(OBJ) $(OBJ_LIBFT)

%.o: %.c $(HEADER)
	$(COMPILER) $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all