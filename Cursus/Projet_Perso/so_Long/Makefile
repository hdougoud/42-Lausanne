NAME	= so_long

OS 		= $(shell uname -s)
CC		= gcc
CFLAGS 	= -Wall -Wextra
MLX_LIB = minilibxs/minilibx-linux/libmlx.a

RED		= \033[1;31m
GREEN	= \033[1;32m
RESET	= \033[0m

ifeq ($(OS), Linux)
	OS_FLAGS = -Lminilibxs/minilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz
else ifeq ($(OS), Darwin)
	OS_FLAGS = -Lminilibxs/minilibx-linux -lmlx -framework OpenGL -framework AppKit
else 
	$(error $(RED)This project isn't compatible with this OS.$(RESET))
endif

SOURCES = so_long.c

OBJECTS	= $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(MLX_LIB) $(OS_FLAGS) -o $(NAME)
	@echo -e "$(GREEN)Done$(RESET)"

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all