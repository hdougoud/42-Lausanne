# Nom de la bibliothèque
NAME = libft.a

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Fichiers sources de la bibliothèque
SOURCES = ft_isascii.c ft_memcpy.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c \
          ft_atoi.c ft_isdigit.c ft_memmove.c ft_split.c ft_strlcpy.c ft_strtrim.c \
          ft_bzero.c ft_isprint.c ft_memset.c ft_strchr.c ft_strlen.c ft_substr.c \
          ft_calloc.c ft_itoa.c ft_putchar_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c \
          ft_isalnum.c ft_memchr.c ft_putendl_fd.c ft_striteri.c ft_strncmp.c ft_toupper.c \
          ft_isalpha.c ft_memcmp.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c

# Fichiers objets générés à partir des fichiers sources
OBJS = $(SOURCES:.c=.o)

# Règle par défaut : compilation de la bibliothèque
all: $(NAME)

# Création de la bibliothèque à partir des fichiers objets
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compilation des fichiers objets à partir des fichiers sources
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour tester la bibliothèque avec un fichier main.c (optionnel)
test: $(NAME)
	$(CC) $(CFLAGS) main.c -L. -lft -o test_program
	./test_program

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJS)

# Nettoyage complet (fichiers objets et la bibliothèque)
fclean: clean
	rm -f $(NAME) test_program

# Reconstruction complète
re: fclean all

# Marquer les cibles spéciales comme non fichiers
.PHONY: all clean fclean re test