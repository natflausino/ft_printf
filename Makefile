# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/15 01:27:28 by nbarreir          #+#    #+#              #
#    Updated: 2021/04/15 22:55:55 by nbarreir         ###   ########.fr        #
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
#	@gcc $(OBJ)
#	@./a.out
	ar rc $(NAME) $(OBJ)

git:
		git add .
		git commit -m "newcommit"
		git push

clean:
		rm -f $(OBJ) a.out

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re
