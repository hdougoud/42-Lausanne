/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:57:02 by lausanne42        #+#    #+#             */
/*   Updated: 2024/11/06 12:13:42 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *recover_last_buff(char *buff)
{
	int i;
	char *new_buff;

	i = 0;
	while (buff[i] != '\n')
		i++;
	i++; 
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char 		*combined_line;
	int			byte_read;
	int			i;

	combined_line = "12\n34";
	if (buff[0] != '\0')
		combined_line = recover_last_buff(buff);
		printf("%s\n", combined_line);
	while (1)
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read <= 0)
			return (NULL);
		buff[byte_read] = '\0';
	}
	return (combined_line);
}

#include <fcntl.h>

int main(void)
{
	int	fd1;
	int	i;

	i = 0;
	fd1 = open("test.txt", O_RDONLY);
		if (fd1 == -1)
			printf("Open failed");
		else
		while (i < 1)
		{
			printf("%s", get_next_line(fd1));
			i++;
		}
	close(fd1);
}