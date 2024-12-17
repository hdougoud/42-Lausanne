# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 18:15:31 by hdougoud          #+#    #+#              #
#    Updated: 2024/12/17 11:48:35 by hdougoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = checker
CFLAGS  = -Wall -Werror -Wextra
GCC 	= cc
LIBFT = ../libft/libft.a

SOURCES = 	checker.c	 \
			rotates.c	  \
			create_list.c  \
			check_errors.c	\
			push_and_swap.c

OBJECTS =	$(SOURCES:.c=.o)

GREEN = \033[1;32m
RESET = \033[0m

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ../libft

$(NAME): $(LIBFT) $(OBJECTS)
	$(GCC) $(CFLAGS) $(OBJECTS) -L../libft -lft -o $(NAME)
	echo -e "$(GREEN)checker done$(RESET)"

%.o: %.c
	$(GCC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C ../libft clean

fclean: clean
	rm -f $(NAME)
	rm -f ../libft/libft.a

re: fclean all

.SILENT:
.PHONY: all clean fclean re