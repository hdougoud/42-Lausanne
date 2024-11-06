/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:54:32 by hdougoud          #+#    #+#             */
/*   Updated: 2024/11/06 21:07:52 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *line, char *buff)
{
	int		i;
	int		j;
	char	*combined_line;

	i = 0;
	j = 0;
	combined_line = malloc(sizeof(char) * (ft_strlen(buff) + ft_strlen(line) + 1));
	if (!combined_line)
		return (NULL);
	if (line != NULL)
	{
		while (line[i])
		{
			combined_line[i] = line[i];
			i++;
		}
		//free line ?
	}
	while (buff[i])
		combined_line[i++] = buff[j++];
	combined_line[i] = '\0';
	return (combined_line);
}

char *get_line(int fd, char *buff, char *combined_line)
{
	int		i;
	int		byte_read;
	char	*temp;
	while (1)
	{
		i = 0;
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read <= 0)
			return (NULL);
		buff[byte_read] = '\0';
		while (buff[i])
		{
			if (buff[i] == '\n')
			{
				buff[i + 1] = '\0';
				combined_line = ft_strjoin(combined_line, buff);
				return (combined_line);
			}
			i++;
		}
		combined_line = ft_strjoin(combined_line, buff);
	}
	return (combined_line);
}

char *get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*combined_line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	combined_line = NULL;
	//if (buff[0] == '\0')
	//rest buffer
	combined_line = get_line(fd, buff, combined_line);
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
		while (i < 10)
		{
			printf("GNL result %s", get_next_line(fd1));
			i++;
		}
	close(fd1);
}