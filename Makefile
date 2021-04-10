# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 15:58:23 by nbarreir          #+#    #+#              #
#    Updated: 2021/04/09 21:26:03 by nbarreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = *.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
INCLUDES = ft_printf.h

all: $(NAME)

$(NAME): $(INCLUDES)
	@gcc $(CFLAGS) -c $(SRC)
	@gcc $(OBJ)
	@./a.out
#	ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ) a.out

fclean: clean
		rm -f $(NAME)

re: fclean all
