# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 13:45:36 by zvandeven         #+#    #+#              #
#    Updated: 2023/11/02 15:22:38 by zvan-de-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RT	= \033[0m
G	= \033[0;32m
B	= \033[0;34m
R 	= \033[0;31m

define HEADER
──────────────────────────────────────────────────────────────────────────────
─██████████████─██████──██████─██████████████───██████████████─████████████───
─██░░░░░░░░░░██─██░░██──██░░██─██░░░░░░░░░░██───██░░░░░░░░░░██─██░░░░░░░░████─
─██░░██████████─██░░██──██░░██─██░░██████░░██───██████████░░██─██░░████░░░░██─
─██░░██─────────██░░██──██░░██─██░░██──██░░██───────────██░░██─██░░██──██░░██─
─██░░██─────────██░░██──██░░██─██░░██████░░████─██████████░░██─██░░██──██░░██─
─██░░██─────────██░░██──██░░██─██░░░░░░░░░░░░██─██░░░░░░░░░░██─██░░██──██░░██─
─██░░██─────────██░░██──██░░██─██░░████████░░██─██████████░░██─██░░██──██░░██─
─██░░██─────────██░░██──██░░██─██░░██────██░░██─────────██░░██─██░░██──██░░██─
─██░░██████████─██░░██████░░██─██░░████████░░██─██████████░░██─██░░████░░░░██─
─██░░░░░░░░░░██─██░░░░░░░░░░██─██░░░░░░░░░░░░██─██░░░░░░░░░░██─██░░░░░░░░████─
─██████████████─██████████████─████████████████─██████████████─████████████───
──────────────────────────────────────────────────────────────────────────────
endef
export HEADER

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Program name
NAME 			= cub3d
LIBMLX			= ./lib/MLX42

# Compiler and flags
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -Wunreachable-code -Ofast -g

# others
RM				= rm -f
MAKE			= make

# Objects 
OBJS_PATH		= objs/
OBJS_B_PATH     = objs_bonus/
OBJS			= $(patsubst $(SRCS_PATH)%.c, $(OBJS_PATH)%.o, $(SRCS_FILES))

# Sources
SRCS_PATH		= srcs/
SRCS			= $(addprefix $(SRCS_PATH), $(SRCS_FILES))

# Includes
HEADERS			= -I ./include -I $(LIBMLX)/include -I $(LIBFT)/include

# library and source files
LIBFT			= ./libs/libft
LIBMLX  		= ./libs/MLX42
LIBS			= $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a -ldl -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm
SRCS_FILES		= $(wildcard $(SRCS_PATH)*.c)

# Progress bar variables
TOTAL 			= $(words $(SRCS_FILES))
CURR  			= 0
PERCENT 		= 0


define update_progress
    $(eval CURR=$(shell echo $$(($(CURR) + 1))))
    $(if $(TOTAL), \
        $(eval PERCENT=$(shell echo $$(($(CURR) * 100 / $(TOTAL))))) \
    )
    @printf "\r\\033[K$(B)Cub3D: $(RT) $(PERCENT)%% ["
    @for i in `seq 1 $(PERCENT)`; do \
        printf "$(G)=$(RT)"; \
    done
	@for i in `seq $(PERCENT) 100`; do \
        printf " "; \
    done
    @printf "]"
endef

define print_header
    @echo "$$HEADER"
endef

					
#------------------------------------------------------------------------------#
#                                 RULES                                        #
#------------------------------------------------------------------------------#

all: $(HEAD) libft libmlx $(NAME)

libmlx:
	@if [ ! -d "$(LIBMLX)" ]; then \
        git -C ./libs clone https://github.com/codam-coding-college/MLX42.git; \
		cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4; \
    fi

$(NAME): $(OBJS_PATH) $(OBJS) $(LIBFT)
	@$(CC)  $(CFLAGS) -o $@ $(OBJS) $(LIBS) $(HEADERS)
	@echo "$(G)\n -- $(NAME) made 🐙 --$(RT)"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@$(CC) $(CFLAGS) -o $@ -c $< 
	$(call update_progress)

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)

libft:
	@$(call print_header)
	@$(MAKE) -C $(LIBFT)

brew:
	brew --version || curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh

glfw: brew
	brew install glfw

cmake : glfw
	cmake --version | brew install cmake
	
clean:
	@rm -rf $(OBJS) $(OBJS_PATH)
	@rm -rf $(OBJS_BONUS) $(OBJS_B_PATH)
	@$(MAKE) -C $(LIBFT) clean
	@rm -rf ./libs/MLX42
	@rm -rf $(LIBMLX)/build
	@echo "$(R)Files succesfully cleaned 🗑$(RT)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY:		all, clean, fclean, brew, cmake, libft, re, libmlx

# VALGRIND #

val: $(NAME)
	valgrind --leak-check=full \
	--show-leak-kinds=all \
	--show-reachable=no \
	--track-origins=yes -s \
	./$(NAME)