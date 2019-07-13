NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

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

all: $(NOM)

$(NOM):	$(OBJ)
	ar -r $(NOM) $(OBJ)
	ranlib $(NOM)

clean:
	@rm -f $(NOM) $(OBJ) *~
	@echo "$(CYA)$(BOL)MLX			$(BLU)obj$(END)$(RED)		[delete]$(END)"
	@rm -f mlx_app
	@echo "$(CYA)$(BOL)MLX			$(BLU)ar$(END)$(RED)		[delete]$(END)"

re: clean all
