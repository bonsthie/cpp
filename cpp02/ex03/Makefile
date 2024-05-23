# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/19 15:05:30 by babonnet          #+#    #+#              #
#    Updated: 2024/05/23 21:08:07 by babonnet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := BSP

##################################### DATA ##########################################
CC := g++
CFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++98
SRC_DIR := src
OBJ_DIR := obj
HSRCS := src -I src/vilualiser
SRC = src/main.cpp \
	src/Fixed.cpp \
	src/Point.cpp \
	src/bsp.cpp \
	src/vilualiser/printLine.cpp \
	src/vilualiser/MlxClass.cpp \
	src/vilualiser/Triangle.cpp \

OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

################################### LIBRARIES #######################################
LIBRARIES = 

LIBRARIES += LIBMLX
LIBMLX_DIR = MacroLibX
LIBMLX_BINARY = $(LIBMLX_DIR)/libmlx.so
LIBMLX_FLAG = -lmlx -lSDL2 -Wl,-rpath,$(LIBMLX_DIR)
LIBMLX_INCLUDE = includes

#include lib for exec
LIB = $(foreach lib,$(LIBRARIES),-L$($(lib)_DIR) $($(lib)_FLAG))
#include lib for *.o
LIB_DIR = $(foreach lib,$(LIBRARIES),-I $($(lib)_DIR)/$($(lib)_INCLUDE))
#build all lib
LIBS_BINARYS += $(foreach lib,$(LIBRARIES), $($(lib)_BINARY))

# Additional linker flags
ADDITIONAL_FLAGS = 

################################ MAKEFILE RULES #####################################
all: $(NAME)

$(NAME): $(LIBS_BINARYS) $(OBJ)
	@echo "$(GREEN)Linking $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIB) $(ADDITIONAL_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@echo "$(YELLOW)Compiling $(notdir $<)...$(NC)"
	@$(CC) $(CFLAGS) -I$(HSRCS) $(LIB_DIR) -c $< -o $@

$(LIBS_BINARYS):
	@echo "$(PURPLE)Building library $(notdir $@)...$(NC)"
	@$(MAKE) -C $(@D) -j$(nproc) --no-print-directory all

clean:
	@if [ -d $(OBJ_DIR) ]; then \
		echo "$(RED)Cleaning object files $(NAME)...$(NC)"; \
		rm -rf $(OBJ_DIR); \
		fi

bonus : $(NAME_BONUS)

lclean:
	@echo "$(RED)Cleaning libraries obj...$(NC)"
	@$(foreach lib,$(LIBRARIES),$(MAKE) -C $($(lib)_DIR) clean > /dev/null;)

fclean: clean
	@echo "$(RED)Cleaning executable $(NAME)...$(NC)"
	@if [ -f $(NAME) ]; then \
		echo "$(RED)Cleaning executable $(NAME)...$(NC)"; \
		rm -f $(NAME); \
		fi
	@echo "$(RED)Cleaning libraries...$(NC)"
	@$(foreach lib,$(LIBRARIES),$(MAKE) -C $($(lib)_DIR) fclean > /dev/null;)

debug: CFLAGS += -g 
debug: clean $(NAME)

CPP11: CFLAGS += -std=c++11
CPP11: clean $(NAME)

CPP98: clean $(NAME)

re: fclean all

-include $(OBJ:.o=.d)

.PHONY: all clean fclean lclean re help

##################################### COLORS ########################################
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[1;33m
PURPLE = \033[0;35m
NC = \033[0m
