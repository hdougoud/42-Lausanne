/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:33:47 by hdougoud          #+#    #+#             */
/*   Updated: 2024/11/11 00:22:12 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char *combine_line(char *buff, char *line)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	new_line = malloc(sizeof(char) * (ft_strlen(buff) + ft_strlen(line) + 1));
	if (new_line == NULL)
		return (NULL);
	if (line != NULL)
	{
		while (line[i])
		{
			new_line[i] = line[i];
			i++;	
		}
		free (line);
	}
	j = 0;
	while (buff[j])
		new_line[i++] = buff[j++];
	new_line[i] = '\0';
	return (new_line);
}

int ft_strchr(char *str, char *old_buff)
{
	int			i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

char *get_next_line(int fd)
{
	static char *old_buff; //TODO initialiser old_buff en NULL
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	line = NULL;
	while (1)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buff[bytes_read] = '\0';
		line = combine_line(buff, line);
		if (ft_strchr(line, old_buff) == 1) //TODO modifier line
			break ;
	}
	return (line);
}

#include <fcntl.h>

int main(void)
{
	int i = 0;
    int fd = open("test.txt", O_RDONLY);

	if (fd == -1)
	{
		printf("Open failed\n");
		return (1);
	}    
	while (i < 1)
	{
	    printf("%s", get_next_line(fd));
		i++;
	}
	return (0);
}
