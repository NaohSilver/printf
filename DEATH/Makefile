# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/17 07:53:43 by niludwig          #+#    #+#              #
#    Updated: 2017/01/06 18:33:15 by niludwig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./src/ft_printf3.c \
	  ./src/ft_print_base.c \
	  ./src/ft_flag.c \
	  ./src/ft_flag.c2 \
	  ./src/ft_flag3.c \
	  ./libft/*.c

OBJ = *.o

LIB = libft.a

HEAD = ./inc/ft_printf.h

NAME = libftprintf.a

.PHONY : clean

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRC) -I $(HEAD)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
