# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 13:01:18 by hdougoud          #+#    #+#              #
#    Updated: 2024/12/11 19:20:46 by hdougoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
GCC		= cc
CFLAGS	= -Wall -Werror -Wextra

LIBFT	= libft/libft.a

SOURCES = 	push_swap.c			check_errors.c		create_list.c \
		  	operator_swap.c 	operator_push.c		sort.c		   \
		  	operator_rotate.c 	quick_sort.c    	self_sort.c		\
		  	operator_rev_rotate.c
		  
OBJECTS	= $(SOURCES:.c=.o)

GREEN = \033[1;32m
RESET = \033[0m


$(LIBFT):
	$(MAKE) -C libft

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	$(GCC) $(CFLAGS) $(OBJECTS) -Llibft -lft -o $(NAME)
	echo -e "$(GREEN)done$(RESET)"
	
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