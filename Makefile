# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jshi <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/11 20:29:02 by jshi              #+#    #+#              #
#    Updated: 2016/10/14 19:22:56 by jshi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = ft_printf print_decimal print_hex print_octal print_str ft_wchar \
		ft_itoa_base concat
SRC_FILES = $(addsuffix .c,$(FILES))

OBJ_FILES = $(addsuffix .o,$(FILES))

CFLAGS = -Wall -Wextra -Werror


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rc $(NAME) $(OBJ_FILES)

$(OBJ_FILES): $(SRC_FILES)
	gcc $(CFLAGS) -c $(SRC_FILES)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
