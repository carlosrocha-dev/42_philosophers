# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 22:19:29 by caalbert          #+#    #+#              #
#    Updated: 2023/08/22 23:26:58 by caalbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=    philosophers
CC=      cc
CFLAGS=  -Wall -Wextra -Werror -pthread -Iinc
SRC_DIR= src
OBJ_DIR= obj
SRC=     main.c
OBJS=    $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all:    $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

