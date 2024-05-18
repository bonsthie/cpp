# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 21:22:53 by babonnet          #+#    #+#              #
#    Updated: 2024/05/18 16:26:31 by babonnet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := Sed_is_for_losers
CC := g++
CFLAGS := -std=c++98 -Wall -Wextra -Werror -mavx2
SRC_DIR := .
HSRCS := .
OBJ_DIR := obj

SRC = main.cpp \
	  File.cpp \
	  sed.cpp  \

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
