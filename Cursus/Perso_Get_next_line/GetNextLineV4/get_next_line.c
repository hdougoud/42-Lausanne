/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:43:31 by hdougoud          #+#    #+#             */
/*   Updated: 2024/11/01 16:15:44 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	int		new_line;
	char	*temp;
	
	r = 1;
	new_line = 0;
	if (buff != NULL)
		add_back(recover_last_line(buff);
	while (r != 0 && buff[i] != '\n')
	{
		temp = malloc(sizeof(char) * BUFFER_SIZE); //add strlen
		i = 0;
		r = read(fd, buff, BUFFER_SIZE);
		while (i < BUFFER_SIZE && buff[i] != '\n')
		{
			temp[i] = buff[i];
			i++;
		}
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
