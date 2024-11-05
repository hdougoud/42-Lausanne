/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:57:02 by lausanne42        #+#    #+#             */
/*   Updated: 2024/11/05 15:29:19 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

static int	newbuff_len(char *buff)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	return (i);
}

static char	*add_back_buffer(char *line, char *buff, int buff_len)
{
	char	*temp;
	int		total_len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	total_len = buff_len + ft_strlen(line);
	temp = malloc(sizeof(char) * (total_len + 1));
	if (!temp)
		return (NULL);
	if (line != NULL)
	{
		while (line[i])
		{
			temp[i] = line[i];
			i++;
		}
	}
	while (j < buff_len)
		temp[i++] = buff[j++];
	temp[i] = '\0';
	return (temp);
}

char	*recover_line(char *buff, char *combined_line )
{
	char	*last_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buff[i] != '\n')
	{
		if (i == BUFFER_SIZE)
		{
			i = 0;
			break ;
		}
		i++;
	}
	if (i == 0)
		last_line = malloc(sizeof(char) * BUFFER_SIZE);
	else 
		last_line = malloc(sizeof(char) * i);
	if (last_line == NULL)
		return (NULL);
	while (i < BUFFER_SIZE)
		last_line[j++] = buff[i++];
	return (add_back_buffer(combined_line, last_line, i - BUFFER_SIZE));
}

char	*get_next_line(int fd)
{
	int			i;
	int			byte_read;
	int			buff_len;
	char		*combined_line;
	static char	buff[BUFFER_SIZE];

	combined_line = NULL;
	byte_read = 1;
	if (buff[0] == '\0')
		combined_line = recover_line(buff, combined_line);
	while (byte_read > 0)
	{
		i = 0;
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read <= 0)
			break ;
		buff_len = newbuff_len(buff);
		while (i < BUFFER_SIZE && buff[i] != '\n')
			i++;
		combined_line = add_back_buffer(combined_line, buff, buff_len);
		if (buff[i] == '\n')
			break ;
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
		while (i < 3)
		{
			printf("%s", get_next_line(fd1));
			i++;
		}
	close(fd1);
}