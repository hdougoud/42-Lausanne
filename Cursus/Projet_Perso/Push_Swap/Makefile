# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 12:49:34 by hdougoud          #+#    #+#              #
#    Updated: 2024/12/06 16:26:24 by hdougoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
GCC		= cc
CFLAGS	= -Wall -Werror -Wextra -g

LIBFT	= libft/libft.a

SOURCES = push_swap.c	check_errors.c	check_duplicates.c	operator_s.c \
		  operator_p.c	operator_r.c

OBJECTS	= $(SOURCES:.c=.o)

GREEN = \033[1;32m
WHITE = \033[1;37m

$(LIBFT):
	$(MAKE) -C libft

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	$(GCC) $(CFLAGS) $(OBJECTS) -Llibft -lft -o $(NAME)
	echo "$(GREEN)done$(WHITE)"
%.o: %.c
	$(GCC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

.SILENT:
.PHONY: all clean fclean re