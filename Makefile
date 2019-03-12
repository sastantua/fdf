# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 01:57:16 by nivergne          #+#    #+#              #
#    Updated: 2019/03/12 16:45:29 by nivergne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

INC = $(shell find include -type f | grep -e \.h$$)
SRC = $(shell find src -type f | grep -e \.c$$)
OBJ = $(SRC:src/%.c=obj/%.o)

MLX = -lmlx -framework OpenGL -framework AppKit
INC_PATH = -Iinclude/ -Ilibft/include -Imlx/
GCC_FLAG = -Wall -Wextra -Werror
CC = gcc $(CFLAGS) $(INC_PATH)
LIB = libft/libft.a

GRN =		\x1b[32m
BLU =		\x1b[33m
RED =		\x1b[31m
PUR =		\x1b[35m
CYA =		\x1b[36m
GRY =		\x1b[40m
UND =		\x1b[4m
REV =		\x1b[7m
BOL =		\x1b[1m
END =		\x1b[0m

all: $(NAME)

$(NAME): makelib obj $(LIB) $(OBJ)
	@echo "$(GRN)$(BOL)FDF [OK]$(END)"
	@$(CC) $(CFLAGS) $(INC_PATH) $(OBJ) $(MLX) -L libft -lft -o $(NAME)

makelib:
	@$(MAKE) -C libft

obj/%.o: src/%.c
	@echo "Building$(BLU) $(patsubst obj/%,%,$(basename $@))$(END)"
	@printf "\033[A"
	@$(CC) $(CFLAGS) -o $@ -c $<
	@printf "\33[2K"

debug: makelib obj $(LIB) $(OBJ)
	@echo "$(GRN)$(BOL)FDF [OK]$(END)"
	@$(CC) $(CFLAGS) -g3 $(INC_PATH) $(OBJ) $(MLX) -L libft -lft -o $(NAME)_debug

fsanitize: makelib obj $(LIB) $(OBJ)
	@echo "$(GRN)$(BOL)FDF [OK]$(END)"
	@$(CC) $(CFLAGS) -g3 -fsanitize=address $(INC_PATH) $(OBJ) $(MLX) -L libft -lft -o $(NAME)_fsanitize

obj:
	@mkdir -p obj

clean_lib:
	@make -C libft clean

clean: clean_lib
	@/bin/rm -fr obj

fclean: clean
	@make -C libft fclean
	@echo "$(RED)Removing $(NAME)$(END)"
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft_clean proj_clean


#patsubst
#remplace le deuxieme arg par le troisieme

#basename 
#remplace le nom en .c par le non sans le .c

