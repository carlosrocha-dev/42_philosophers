# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 21:56:40 by caalbert          #+#    #+#              #
#    Updated: 2023/08/29 11:07:08 by caalbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo_bonus
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g
RM		= rm -rf
SRCS	= 					\
			main.c			\
			init.c			\
			utils.c			\
			terminate.c		\
			simulations.c

OBJ		= $(SRCS:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
OBJ_PATH = obj/
SRCS_PATH = src/
INC = -I ./inc
$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)
CYAN			:= \033[1;36m
YELLOW			:= \033[1;33m
GREEN			:= \033[1;32m
RED				:= \033[1;31m
RESET			:= \033[0m

all: $(NAME)
	@echo "------------------------------------------"
	@echo ""
	@echo "${GREEN}\
\n/* ************************************************************************** */\
\n/*                                                                            */\
\n/*            :::      ::::::::                                               */\
\n/*          :+:      :+:    :+:                                               */\
\n/*        +:+ +:+         +:+      PHILOSOPHERS IS DONE (BONUS).              */\
\n/*      +#+  +:+       +#+                                                    */\
\n/*    +#+#+#+#+#+   +#                                                        */\
\n/*         #+#    #+#           By: caalbert <caalbert@student.42sp.org.br>   */\
\n/*        ###   ########.fr                                                   */\
\n/*                                                                            */\
\n/* ************************************************************************** */\n\
	${RESET}"
	@echo ""
	@echo "$(YELLOW)To run the bonus project:$(RESET)"
	@echo "> ./philo_bonus [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]"
	@echo ""
	@echo ""

$(NAME): $(OBJS)
	@$(CC) -lpthread $(CFLAGS) $(OBJS) -o $(NAME) $(INC)

clean:
	@$(RM) $(OBJ_PATH)


fclean: clean
	@$(RM) $(NAME)


re: fclean all
