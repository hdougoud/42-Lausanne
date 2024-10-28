/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:57:02 by lausanne42        #+#    #+#             */
/*   Updated: 2024/10/25 16:01:52 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	gnl_strlen(char *s)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

static int	stringlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*combine_line(char *buff, int m_size, char* currentline)
{
	char	*temp;
	int		b;
	int		i;
	int		sl;
	
	i = 0;
	b = 0;
	sl = stringlen(currentline);
	temp = malloc(sizeof(char) * (sl + m_size));
	while (sl > 0)
	{
		temp[i] = currentline[i];
		i++;
		sl--;
	}
	while (m_size > b)
		temp[i++] = buff[b++];
	printf("%s\n", temp);
	return (temp);
	
}

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE];
	char*			current_line;
	int 			m_size;

	current_line = "";
	while (0 < read(fd, buff, BUFFER_SIZE))
	{
		m_size = gnl_strlen(buff);
		combine_line(buff, m_size, current_line);
	}
	return (current_line);
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