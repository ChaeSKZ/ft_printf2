# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 13:52:59 by jugingas          #+#    #+#              #
#    Updated: 2022/11/25 11:34:22 by jugingas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	src/flag_p.c	\
				src/ft_printf.c		\
				src/ft_putchar_fd.c	\
				src/ft_putnbr_base.c\
				src/ft_putnbr_fd.c	\
				src/ft_putstr_fd.c	\
				src/ft_strlen.c

OBJ			=	$(SRC:.c=.o)

CFLAGS		+=	-Wall -Wextra -Werror -I./include

NAME		=	libftprintf.a

all:	$(NAME)

$(NAME): $(OBJ)
	clang -c $(CFLAGS) $(SRC)
	mv *.o ./src/
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
