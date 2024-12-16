# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 13:01:18 by hdougoud          #+#    #+#              #
#    Updated: 2024/12/16 13:53:18 by hdougoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
GCC		= cc
CFLAGS	= -Wall -Werror -Wextra

LIBFT	= libft/libft.a

SOURCES = push_swap.c		instr_push.c		radix_sort.c  \
		  instr_swap.c		quick_sort.c		create_list.c  \
		  select_sort.c		instr_rotate.c		check_errors.c  \
		  instr_rev_rotate.c

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