/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:57:02 by lausanne42        #+#    #+#             */
/*   Updated: 2024/10/25 12:14:22 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlen(char *s, int readed)
{
	int	i;

	i = 0;
	while (i < readed)
	{
		i++;
		if (s[i] == '\n')
			return (i);
	}
	return (i);
}

char	*get_next_line(int fd)
{
	char			buff[BUFFER_SIZE];
	static char*	current_line;
	int				i;
	int				m_size;
	int				readed;
	int				buffi;


	i = 0;
	while (buff[i] != '\n')
	{
		buffi = 0;
		readed = read(fd, buff, BUFFER_SIZE);
		m_size = ft_strlen(buff, readed);
		current_line = malloc(sizeof(char) * m_size + i);
		while (m_size > 0)
		{
			if (buff[i] == '\n')
				return (current_line);
			current_line[i] = buff[buffi];
			i++;
			buffi++;
			m_size--;
		}
	}
	current_line[i] = '\0';
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