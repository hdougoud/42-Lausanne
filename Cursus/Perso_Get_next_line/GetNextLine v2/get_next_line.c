/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:43:31 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/31 17:22:50 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//static char *join_list(t_line **current_line)
//{
//	int i;
//	int total;
//	t_line	*total_line;
//	
//	total_line = *current_line;
//	total = 0;
//	i = 0;
//	printf("%s\n", total_line->content);
//	while (total_line != NULL)
//	{
//		i = 0;
//		while (total_line->content[i] != '\n' && i < (BUFFER_SIZE))
//			i++;
//		total += i;
//		(total_line = total_line->next);
//	}
//	return ("test");
//}

static char *add_back_buff(char *buff, t_line **current_line)
{
	t_line *new_buff;
	t_line *last_buff;

	new_buff = malloc(sizeof(t_line));
	if(new_buff == NULL)
		return (NULL);
	new_buff->content = buff;
	new_buff->next = NULL;
	if (*current_line == NULL)
		*current_line = new_buff;
	else
	{
		last_buff = *current_line;
		while (last_buff->next != NULL)
			last_buff = last_buff->next;
		last_buff->next = new_buff;
	}
	printf("addback %s\n", (*current_line)->content);
}

static t_line *new_list(char *buff, t_line **current_line)
{
	t_line *new_list;

	new_list = malloc(sizeof(t_line));
	if(new_list == NULL)
		return (NULL);
	new_list->content = buff;
	new_list->next = NULL;
	*current_line = new_list;
	printf("newlist %s\n", (*current_line)->content);
	return (new_list);
}

char *get_next_line(int fd)
{
	t_line *current_line;
	t_line *total_line;
	static char buff[BUFFER_SIZE];
	char *temp;
	int i;
	int n;

	n = read(fd, buff, BUFFER_SIZE);
	current_line = NULL;
	new_list(buff, &current_line);
	printf("firstcurrent %s\n", current_line->content);
	while(n > 0)
	{
		i = 0;
		n = read(fd, buff, BUFFER_SIZE);
		temp = malloc(sizeof(char) * BUFFER_SIZE);
		while (buff[i] != '\n' && i < BUFFER_SIZE)
		{
			temp[i] = buff[i];
			i++;
		}
		if (buff[i] == '\n')
			n = 0;
		add_back_buff(temp, &current_line);
	}
	printf("lastcurrent %s\n", current_line->content);
	return (/*join_list(&current_line)*/"test");
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