/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:43:31 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/30 20:28:13 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *add_back_buff(char *buff, t_line **current_line)
{
	t_line *new_buff;

	new_buff = malloc(sizeof(t_line));
	if(new_buff == NULL)
		return (NULL);
	new_buff = *current_line;
	while (new_buff->next != NULL)
		new_buff = new_buff->next;
	new_buff->content = buff;
	printf("%s", new_buff->content);
	new_buff->next = NULL;
}

static t_line *new_list(char *buff)
{
	t_line *new_list;

	new_list = malloc(sizeof(t_line));
	if(new_list == NULL)
		return (NULL);
	new_list->content = buff;
	new_list->next = NULL;
	return (new_list);
}

char *get_next_line(int fd)
{
	t_line *current_line;
	static char buff[BUFFER_SIZE];
	int r;

	r = read(fd, buff, BUFFER_SIZE);
	current_line = new_list(buff);
	printf("%s", current_line->content);
	while(r > 0)
	{
		r = read(fd, buff, BUFFER_SIZE);
		add_back_buff(buff, &current_line);
	}
	return (current_line->content);
}

#include <fcntl.h>

int main(void)
{
	int fd1;
	int i;

	i = 0;
	fd1 = open("test.txt", O_RDONLY);
		if(fd1 == -1)
			printf("Open failed");
		else
			printf("%s\n", get_next_line(fd1));
	close(fd1);
}