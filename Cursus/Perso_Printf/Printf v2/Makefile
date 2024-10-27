# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/27 18:26:38 by hdougoud          #+#    #+#              #
#    Updated: 2024/10/27 22:00:18 by hdougoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
GCC = CC
SOURCES = ft_printf.c ft_print_numbers.c
OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
	
clean :
	rm -rf $(OBJECTS)
	
fclean: clean
	rm -rf $(NAME)

re : fclean all
	
.PHONY: all clean fclean


