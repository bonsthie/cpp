# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 22:19:06 by babonnet          #+#    #+#              #
#    Updated: 2024/05/13 23:28:20 by babonnet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := PhoneBook
CC := g++
CFLAGS := -std=c++98 -Wall -Wextra -Werror
SRC_DIR := src
HSRCS := include
OBJ_DIR := obj

SRC := Contact.cpp \
	action/exit.cpp \
	action/add.cpp \
	action/search.cpp \
	PhoneBook.cpp \

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

silentClean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Cleaning executable $(NAME)...$(NC)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all avx2 clean fclean re silentClean
