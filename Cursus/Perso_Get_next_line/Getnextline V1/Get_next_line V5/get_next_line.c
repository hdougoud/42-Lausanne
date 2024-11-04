/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:57:02 by lausanne42        #+#    #+#             */
/*   Updated: 2024/11/04 16:28:19 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	new_line_len(char *buff)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	int			i;
	int			byte_read;
	char		*temp;
	static char	buff[BUFFER_SIZE];
	
	i = 0;
	while(buff[i] != '\n')
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read <= 0)
			break;
		temp = malloc(sizeof(char) * (new_line_len(buff)+ 1));
	}
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