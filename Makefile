# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 01:57:16 by nivergne          #+#    #+#              #
#    Updated: 2019/07/20 14:03:09 by nivergne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_FDF =			main.c\
					error.c\
					init_struct.c\
					init_fd.c\
					get_dimension.c\
					parse_line.c\
					allocate_map.c\
					fill_map.c\
					free_end.c\
					fdf.c\
					fdf_init.c\
					bresenham.c\
					event_handler.c\
					debug.c

SRC = $(addprefix $(SRC_PATH)/, $(SRC_FDF))
OBJ = $(SRC:src/%.c=obj/%.o)

SRC_PATH = src/
INC = -I./include 
INC_PATH = -Iinclude/ -Ilibft/include -Imlx/
MLX = -framework OpenGL -framework AppKit -lmlx
GCC_FLAG = -Wall -Wextra -Werror -g
CC = gcc $(GCC_FLAG) $(INC_PATH)
LIB = libft/libft.a

GRN =		\x1b[32m
YEL =		\x1b[33m
BLU =		\x1b[34m
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
	@echo "$(BOL)$(GRN)FDF			$(BLU)compile$(GRN)		[OK]$(END)"
	@$(CC) $(CFLAGS) $(INC_PATH) $(OBJ) $(MLX) -L libft -lft -L mlx -lmlx -o $(NAME)

makelib:
#	uncomment nextline if libmlx.a has been delete (comment to avoid all warnings from that dirty lib)
#	@$(MAKE) -C mlx
	@$(MAKE) -C libft

obj/%.o: src/%.c
	@echo "Building$(BLU) $(patsubst obj/%,%,$(basename $@))$(END)"
	@printf "\033[A"
	@$(CC) $(CFLAGS) -o $@ -c $<
	@printf "\33[2K"

debug: makelib obj $(LIB) $(OBJ)
	@echo "$(BOL)$(GRN)FDF			$(BLU)debug$(GRN)		[OK]$(END)"
	@$(CC) $(CFLAGS) -g3 $(INC_PATH) $(OBJ) $(MLX) -L libft -lft -o $(NAME)_debug

fsanitize: makelib obj $(LIB) $(OBJ)
	@echo "$(BOL)$(GRN)FDF			$(BLU)fsanitize$(GRN)	[OK]$(END)"
	@$(CC) $(CFLAGS) -g3 -fsanitize=address $(INC_PATH) $(OBJ) $(MLX) -L libft -lft -o $(NAME)_fsanitize

obj:
	@mkdir -p obj

clean_lib:
	@make -C libft clean

clean: clean_lib
	@/bin/rm -fr obj

fclean: clean
	@make -C mlx clean
	@make -C libft fclean
	@echo "$(CYA)$(BOL)FDF			$(BLU)bin$(END)$(RED)		[delete]$(END)"
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft_clean proj_clean


#INC = $(shell find include -type f | grep -e \.h$$)
#SRC = $(shell find src -type f | grep -e \.c$$)
#patsubst: remplace le deuxieme arg par le troisieme
#basename: remplace le nom en .c par le non sans le .c
