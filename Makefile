# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jshi <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/18 21:00:39 by jshi              #+#    #+#              #
#    Updated: 2016/10/31 16:23:09 by jshi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = ft_printf parse_conversion ft_itoa_base concat ft1 ft2 wchar \
		print_integer print_string print_char print_float get_float \
		print_float_e print_float_g print_float_hex print_bonus print_color
SRC_FILES = $(addsuffix .c,$(FILES))

OBJ_FILES = $(addsuffix .o,$(FILES))

CFLAGS = -Wall -Wextra -Werror


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

$(OBJ_FILES): $(SRC_FILES)
	gcc $(CFLAGS) -c $(SRC_FILES)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
