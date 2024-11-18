/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:33:47 by hdougoud          #+#    #+#             */
/*   Updated: 2024/11/15 10:36:32 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void safe_free(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*get_back_buff(char *line, char **old_buff, int len)
{
	char	*new_buff;
	int		i;
	int		j;
	int		newline;

	i = 0;
	while (line[i] != '\n' && i < len)
		i++;
	i++;
	if (line[i] == '\0')
	{
		*old_buff = NULL;
		return (line);
	}
	j = 0;
	newline = i;
	new_buff = malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!new_buff)
		return (NULL);
	while (line[i])
		new_buff[j++] = line[i++];
	new_buff[j] = '\0';
	*old_buff = new_buff;
	line[newline] = '\0';
	return (line);
}

char	*recover_last_buff(char *old_buff)
{
	int		i;
	char	*start;
	if (!old_buff)
		return (NULL);
	i = 0;
	start = malloc(sizeof(char) * (ft_strlen(old_buff) + 1));
	if (!start)
	{
		safe_free(&old_buff);
		return (NULL);
	}
	while (old_buff[i])
	{
		start[i] = old_buff[i];
		i++;		
	}
	start[i] = '\0';
	safe_free(&old_buff);
	return (start);
}



char	*combine_line(char *buff, char *line)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	new_line = malloc(sizeof(char) * (ft_strlen(buff) + ft_strlen(line) + 1));
	if (new_line == NULL)
	{
		safe_free(&line);
		return (NULL);
	}
	if (line != NULL)
	{
		while (line[i])
		{
			new_line[i] = line[i];
			i++;	
		}
		safe_free(&line);
	}
	j = 0;
	while (buff[j])
		new_line[i++] = buff[j++];
	new_line[i] = '\0';
	return (new_line);
}

int	ft_strchr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

char	*read_line(int fd, char *line, char *buff, char **old_buff)
{
	int	bytes_read;

	while (1)
	{
	if (ft_strchr(line) == 1)
			break ;
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
		{
			if (line && *line)
			{
				*old_buff = NULL;
				break ;
			}
				return (NULL);
		}
		buff[bytes_read] = '\0';
		if ((line = combine_line(buff, line)) == NULL)
			return (NULL);
	}
	if (bytes_read > 0)
		line = get_back_buff(line, old_buff, ft_strlen(line));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*old_buff;
	char		buff[BUFFER_SIZE + 1];
	char		*line; 

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (old_buff != NULL)
	{
		line = recover_last_buff(old_buff);
		if (!line)
			return (NULL);
		old_buff = NULL;
	}
	line = read_line(fd, line, buff, &old_buff);
	if (!line)
		return (NULL);
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
	while (i < 10)
	{
	    printf("Result %s\n", get_next_line(fd));
		i++;
	}
	return (0);
}
