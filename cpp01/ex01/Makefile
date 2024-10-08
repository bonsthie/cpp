# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 17:27:24 by babonnet          #+#    #+#              #
#    Updated: 2024/08/06 14:03:02 by bonsthie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ZombieHorde
CC := g++
CFLAGS := -std=c++98 -Wall -Wextra -Werror
SRC_DIR := .
HSRCS := .
OBJ_DIR := obj

SRC = main.cpp \
	Zombie.cpp \
	zombieHorde.cpp \

ifeq ($(VERBOSE),true)
	CFLAGS += -D VERBOSE
endif


OBJS := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC))

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[1;33m
PURPLE = \e[0;35m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Linking $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@echo "$(YELLOW)Compiling $(notdir $<)...$(NC)"
	@$(CC) $(CFLAGS) -I $(HSRCS) -o $@ -c $<

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Cleaning executable $(NAME)...$(NC)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
