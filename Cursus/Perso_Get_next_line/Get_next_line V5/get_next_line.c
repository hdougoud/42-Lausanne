/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:53:23 by hdougoud          #+#    #+#             */
/*   Updated: 2024/11/04 17:53:37 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//char *combine_buffer(char *str)
//{
//
//}

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
			printf("%s", buff);
		if (byte_read <= 0)
			break;
		temp = malloc(sizeof(char) * (new_line_len(buff)+ 1));
		if (!temp)
			return (NULL);
		while (buff[i] != '\n' && i < BUFFER_SIZE)
		{
			temp[i] = buff[i];
			i++;
		}
		if (buff[i] == '\n')
			break;
	}
	return ("test");
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