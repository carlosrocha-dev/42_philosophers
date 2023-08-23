# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 22:19:29 by caalbert          #+#    #+#              #
#    Updated: 2023/08/22 22:19:30 by caalbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	philosophers
cc= 	cc
CFLAGS=	-Wall -Wextra -Werror -pthread
SRC=\
		main.c
OBJ=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(cc) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean

re:	fclean all
