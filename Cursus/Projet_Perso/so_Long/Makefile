NAME		= so_long
OS			= $(shell uname -s)
CC			= gcc
CFLAGS		=-g # -Wall -Werror -Wextra
MACOS_DIR	= mlx/minilibx-macos
LINUX_DIR	= mlx/minilibx-linux

RED			= \033[1;31m
GREEN		= \033[1;32m
RESET		= \033[0m

ifeq ($(OS), Linux)
	OS_FLAGS = -L$(LINUX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz
	LIB_DIR  = $(LINUX_DIR)
else ifeq ($(OS), Darwin)
	OS_FLAGS = -L$(MACOS_DIR) -lmlx -framework OpenGL -framework AppKit -lz
	LIB_DIR  = $(MACOS_DIR)
endif

SOURCES	= main.c

OBJECTS	= $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(OS_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIB_DIR) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re