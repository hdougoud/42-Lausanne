NAME		= so_long
OS			= $(shell uname -s)
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
MACOS_DIR	= mlx/minilibx-macos
LINUX_DIR	= mlx/minilibx-linux
LIBFT		= libft/libft.a

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

SRC_DIR = Sources/
SRCS	= main.c			file_to_image.c 	init_map.c	show_error.c \
		  so_long_utils.c 	gameplay.c			clean_exit.c init_mlx.c \
		  parsing_map.c

SOURCES = $(addprefix $(SRC_DIR), $(SRCS))

OBJ_DIR	= Objects/
OBJS	= $(SRCS:.c=.o)
OBJECTS = $(addprefix $(OBJ_DIR), $(OBJS))
  
all: $(OBJ_DIR) $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(OBJECTS) $(OS_FLAGS) -Llibft -lft -o $(NAME)
	echo "$(GREEN)$(NAME) compiled!$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -I$(LIB_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

.SILENT:
.PHONY: all clean fclean re