NAME	= so_long

OS 		= $(shell uname -s)
CC		= gcc
CFLAGS 	= -Wall -Wextra

RED		= \033[1;31m
GREEN	= \033[1;32m
RESET	= \033[0m


ifeq ($(OS), Linux)
	OS_FLAGS = -Lminilibxs/minilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz
else ifeq ($(OS), Macos)
	OS_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
endif

SOURCES = so_long.c

OBJECTS	= $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(OS_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re