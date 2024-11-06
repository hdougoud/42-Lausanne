/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:57:02 by lausanne42        #+#    #+#             */
/*   Updated: 2024/11/06 18:40:35 by hdougoud         ###   ########.fr       */
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

char	*ft_strjoin(char *line, char *temp, int byte_read)
{
	char	*combined_line;
	int		i;
	int		j;

	j = 0;
	i = 0;
	combined_line = malloc(sizeof(char) * (byte_read + ft_strlen(line) + 1));
	if (combined_line == NULL)
		return (NULL);
	if (line != NULL)
	{
		while (line[i])
		{
			combined_line[i] = line[i];
			i++;
		}
	}
	while (temp[j] != '\0')
		combined_line[i++] = temp[j++];
	combined_line[i] = '\0';
	return (combined_line);
}
char *recover_last_buff(char *buff, char *new_buff)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < BUFFER_SIZE && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	new_buff = malloc(sizeof(char) * (BUFFER_SIZE - i + 1));
	if (new_buff == NULL)
		return (NULL);
	new_buff[j++] = buff[i++];
	while (buff[i] != '\0' && buff[i] != '\n')
	{
		new_buff[j++] = buff[i++];
	}
	new_buff[j] = '\0';
	return (new_buff);
}

int	check_newline(char *buff, int byte_read)
{
	int	i;

	i = 0;
	while (i < byte_read && buff[i] != '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char 		*combined_line;
	char		*temp;
	int			byte_read;
	int			i;

	combined_line = NULL;
	if (buff[0] != '\0')
		combined_line = recover_last_buff(buff, combined_line);
	while (1)
	{
		i = 0;
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read < 0)
			return (NULL);
		if (byte_read == 0)
			return (combined_line);
		buff[byte_read] = '\0';
		temp = malloc(sizeof(char) * (check_newline(buff, byte_read + 2)));
		if (temp == NULL)
			return (NULL);
		while (buff[i] != '\n' && buff[i] != '\0')
		{
			temp[i] = buff[i];
			i++;
		}
		if (buff[i] == '\n')
		{
			temp[i] = buff[i];
			i++;
		}
		temp[i] = '\0';
		combined_line = ft_strjoin(combined_line, temp, i);
		if (buff[i] == '\n')
			break ;
	}
	//buff = combined_line;
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