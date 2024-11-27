# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 12:49:34 by hdougoud          #+#    #+#              #
#    Updated: 2024/11/27 14:06:12 by hdougoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
GCC  = cc
CFLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a

SOURCES = push_swap.c ft_atol.c check_errors.c

OBJECTS = $(SOURCES:.c=.o)

$(LIBFT):
	$(MAKE) -C libft

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	$(GCC) $(CFLAGS) $(OBJECTS) -Llibft -lft -o $(NAME)

%.o: %.c
	$(GCC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all
	
.PHONY: all clean fclean re