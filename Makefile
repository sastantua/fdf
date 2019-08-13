# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 01:57:16 by nivergne          #+#    #+#              #
#    Updated: 2019/08/13 02:27:40 by nivergne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_PATH := src/
OBJ_PATH := obj/
INC_PATH := include/

INC_FDF =			define.h\
					fdf.h

INC_FDF := $(addprefix $(INC_PATH), $(INC_FDF))

SRC_GENERAL =		main.c\
					error.c\
					debug.c\
					free_end.c

SRC_GENERAL := $(addprefix general/, $(SRC_GENERAL))
OBJ_GENERAL := $(addprefix general/, $(addsuffix .o, $(basename $(notdir $(SRC_GENERAL)))))

SRC_PARSE =			init_fd.c\
					init_struct.c\
					get_dimension.c\
					allocate_map.c\
					parse_line.c\
					fill_map.c

SRC_PARSE := $(addprefix parse/, $(SRC_PARSE))
OBJ_PARSE := $(addprefix parse/, $(addsuffix .o, $(basename $(notdir $(SRC_PARSE)))))

SRC_DISPLAY =		fdf.c\
					fdf_init.c\
					bresenham.c\
					event_handler.c\

SRC_DISPLAY := $(addprefix display/, $(SRC_DISPLAY))
OBJ_DISPLAY := $(addprefix display/, $(addsuffix .o, $(basename $(notdir $(SRC_DISPLAY)))))

SRC := $(addprefix $(SRC_PATH), $(SRC_GENERAL))
SRC += $(addprefix $(SRC_PATH), $(SRC_PARSE))
SRC += $(addprefix $(SRC_PATH), $(SRC_DISPLAY))

OBJ := $(addprefix $(OBJ_PATH), $(OBJ_GENERAL))
OBJ += $(addprefix $(OBJ_PATH), $(OBJ_PARSE))
OBJ += $(addprefix $(OBJ_PATH), $(OBJ_DISPLAY))

INC = -I./include 
INC_PATH = -Iinclude/ -Ilibft/include -Imlx/
MLX = -framework OpenGL -framework AppKit -lmlx
GCC_FLAG = -Wall -Wextra -Werror -g3 -fsanitize=address
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

DARK_PURPLE		=			\033[38;2;65;0;255m
DARK_PINK		= 			\033[38;2;86;0;255m
PURPLE			=			\033[38;2;114;0;255m
PINK			=			\033[38;2;152;0;255m

all: $(NAME)

$(NAME): makelib obj $(LIB) $(OBJ)
	@echo "$(BOL)$(GRN)FDF			$(BLU)compile$(GRN)		[OK]$(END)"
	@$(CC) $(CFLAGS) $(INC_PATH) $(OBJ) $(MLX) -L libft -lft -L mlx -lmlx -o $(NAME)

makelib:
#	uncomment nextline if libmlx.a has been delete (comment to avoid all warnings from that dirty lib)
#	@$(MAKE) -C mlx
	@$(MAKE) -C libft

obj/%.o: src/%.c $(INC_FDF)
	@echo "Building$(BLU) $(patsubst obj/%,%,$(basename $@))$(END)"
	@printf "\033[A"
	@$(CC) $(CFLAGS) -o $@ -c $<
	@printf "\33[2K"

debug: makelib obj $(LIB) $(OBJ)
	@echo "$(BOL)$(GRN)FDF			$(BLU)debug$(GRN)		[OK]$(END)"
	@$(CC) $(CFLAGS) -g3 $(INC_PATH) $(OBJ) $(MLX) -L libft -lft -o $(NAME)_debug

fsanitize: makelib obj $(LIB) $(OBJ)
	@echo "$(BOL)$(GRN)FDF			$(BLU)fsanitize$(GRN)	[OK]$(END)"
	@$(CC) $(CFLAGS) -g3 -fsanitize=address $(INC_PATH) $(OBJ) $(MLX) -L libft -lft -L mlx -lmlx -o $(NAME)_fsanitize

obj:
	@mkdir -p obj
	@mkdir -p obj/general
	@mkdir -p obj/parse
	@mkdir -p obj/display


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

easter_egg:
	@echo "$(DARK_PURPLE)______ _   ___   __ ______ _____ _____ _____ _____ _____ _   _"
	@echo "$(DARK_PURPLE)| ___ \ | | \ \ / / | ___ \_   _|_   _/  __ \  _  |_   _| \ | |"
	@echo "$(DARK_PINK)| |_/ / | | |\ V /  | |_/ / | |   | | | /  \/ | | | | | |  \| |"
	@echo "$(PURPLE)| ___ \ | | | \ /   | ___ \ | |   | | | |   | | | | | | |     |"
	@echo "$(PINK)| |_/ / |_| | | |   | |_/ /_| |_  | | | \__/\ \_/ /_| |_| |\  |"
	@echo "$(PINK)\____/ \___/  \_/   \____/ \___/  \_/  \____/\___/ \___/\_| \_/"
	@echo "$(END)"

.PHONY: all clean fclean re libft_clean proj_clean


#INC = $(shell find include -type f | grep -e \.h$$)
#SRC = $(shell find src -type f | grep -e \.c$$)
#patsubst: remplace le deuxieme arg par le troisieme
#basename: remplace le nom en .c par le non sans le .c
