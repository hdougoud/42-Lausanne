/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:43:31 by hdougoud          #+#    #+#             */
/*   Updated: 2024/11/04 14:23:25 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void *add_back(char *buff, t_line **current_line)
{
	t_line *last_node;
	t_line *new_node;

	last_node = *current_line; // double

	new_node = malloc(sizeof(t_line));
	if (new_node == NULL)
		return (NULL);
	new_node->content = buff;
    new_node->next = NULL;
		
	if (*current_line == NULL)
	{
		*current_line = new_node;
		return (0);
	}
	
	last_node = *current_line;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = new_node;
	return (0);
}
char *combine_node(t_line **current_line)
{
	int		i;
	int		j;
	int		count_line;
	t_line	*count_list;
	t_line	*add_node;
	char	*combined_line;

	count_line = 0;
	count_list = *current_line;
	add_node = *current_line;
	while (count_list)
	{
		i = 0;
		while(i < BUFFER_SIZE && count_list->content[i++] != '\n')
			count_line++;
	}
	combined_line = malloc(sizeof(char) * (count_line + 1));
	if (!combined_line)
		return (NULL);
	j = 0;
	while (add_node != NULL)
	{
		i = 0;
		while(i < BUFFER_SIZE && add_node->content[i] != '\n')
		{
			combined_line[j] = add_node->content[i];
			i++;
			j++;
		}
		add_node = add_node->next;
	}
	combined_line[j] = '\0';
	return (combined_line);
}










void *recover_last_line(char *buff)
{
	int		i;
	char	*temp;

	i = 0;
	temp = malloc(sizeof(char) * BUFFER_SIZE); //add strlen
	while (i < BUFFER_SIZE && buff[i] != '\n')
	{
		temp[i] = buff[i];
		i++;
	}
	printf("test recover last line %s\n", temp);
	return (0);
}

int read_file(int fd, t_line **current_line, char *buff)
{
	int		r;
	int		i;
	char	*temp;
	
	r = 1;
	while (r > 0)
	{
		temp = malloc(sizeof(char) * (BUFFER_SIZE + 1)); //add strlen
		i = -1;
		r = read(fd, buff, BUFFER_SIZE);
		if (r <= 0)
			break;
		while (i < r && buff[++i] != '\n')
			temp[i] = buff[i];
		if (buff[i] == '\n')
			i++;
		i++;
		temp[i] = '\0';
		add_back(temp, current_line);
	}
	return (r);
}

char *get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	t_line		*current_line;
	char		*temp;

	current_line = NULL;
	if (read_file(fd, &current_line, buff) == -1)
		return (NULL);
	return (combine_node(&current_line));
}

#include <fcntl.h>

int main(void)
{
	int fd;
	int	i;

	i = 0;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Open Faild\n");
		return 1;
	}
	else
	{
		printf("Open sucessfull\n");
		while (i <= 2)
		{
			printf("GNL result %s\n", get_next_line(fd));
			i++;
		}
	}
	return (0);
}
