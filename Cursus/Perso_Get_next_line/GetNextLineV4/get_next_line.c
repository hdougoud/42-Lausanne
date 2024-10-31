/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:43:31 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/31 23:33:21 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void *add_back(char *buff, t_line **current_line)
{
	t_line *last_node;
	t_line *new_node;

	last_node = *current_line;

	new_node = malloc(sizeof(t_line));
	if (new_node == NULL)
		return (NULL);
	new_node->content = buff;
    new_node->next = NULL;
		
	if (*current_line == NULL)
	{
		*current_line = new_node; //ajouter un premier maillon
		return (0);
	}
	
	last_node = *current_line;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = new_node;
	return (0);
}

char *get_next_line(int fd)
{
	static char buff[BUFFER_SIZE];
	t_line *current_line;

	current_line = NULL;
	add_back("hello", &current_line);
	add_back("world", &current_line);
	add_back("how", &current_line);
	while (current_line != NULL)
	{
		printf("%s\n", current_line->content);
		current_line = current_line->next;
	}
	return ("test");
}

#include <fcntl.h>

int main(void)
{
	int fd;
	
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Open Faild\n");
		return 1;
	}
	else
		printf("%s\n", get_next_line(fd));
	return (0);
}
