# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 22:19:29 by caalbert          #+#    #+#              #
#    Updated: 2023/08/26 20:42:11 by caalbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= 		philo
CC=			cc
CFLAGS=		-Wall -Wextra -Werror -pthread -Iinc
SRC_DIR= 	src
OBJ_DIR= 	obj

SRC=	 											\
		$(SRC_DIR)/main.c							\
		$(SRC_DIR)/philosophers/philo.c				\
		$(SRC_DIR)/simulation/simulation.c			\
		$(SRC_DIR)/simulation/start_simulation.c	\
		$(SRC_DIR)/utils/utils.c					\
		$(SRC_DIR)/utils/validate_inputs.c			\
		$(SRC_DIR)/utils/utils_simulations.c		\
		$(SRC_DIR)/utils/terminate.c				\
		$(SRC_DIR)/init/init.c

OBJS=	 	$(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRC:.c=.o))

all:	 $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
