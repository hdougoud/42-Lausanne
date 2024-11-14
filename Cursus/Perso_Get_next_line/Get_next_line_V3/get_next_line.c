/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:49:32 by hdougoud          #+#    #+#             */
/*   Updated: 2024/11/14 19:48:48 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	safe_free(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (ptr == 0)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strchr(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

char	*combine_line(char *line, char *buff)
{
	char	*joined_line;

	if (line == NULL)
		joined_line = ft_strdup(buff);
	else
		joined_line = ft_strjoin(line, buff);
	if (joined_line == NULL)
		return (NULL);
	safe_free(&line);
	return (joined_line);
}

char	*read_line(int fd, char *current_line)
{
	int		bytes_read;
	char	buff[BUFFER_SIZE + 1];

	while (1)
	{
		if (ft_strchr(buff) == 1)
			break;
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			safe_free(&current_line);
			return NULL;
		}
		if (bytes_read == 0)
			break;
		buff[bytes_read] = '\0';
		current_line = combine_line(current_line, buff);
		if (current_line == NULL)
			return (NULL);
	}
	if (bytes_read == 0 && current_line == NULL) 
		return (NULL);
	return (current_line);
}

char *manage_stash(char *line, char **stash)
{
	char 	*backup;
	char	*complete_line;
	int		i;
	
	backup = line;
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (line);
	i++;
	line += i;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*final_line;

	final_line = NULL;
	if (stash)
	{
		final_line = ft_strdup(stash);
			if (!final_line)
				return (NULL);
	}
	stash = NULL;
	final_line = read_line(fd, final_line);
	final_line = manage_stash(final_line, &stash);
	return (final_line);
}

#include <fcntl.h>

int main(void)
{
	int i = 0;
    int fd = open("test.txt", O_RDONLY);
	char *line;

	if (fd == -1)
	{
		printf("Open failed\n");
		return (1);
	}    
	while (i < 11)
	{
		line = get_next_line(fd);
	    printf("Result %s\n", line);
		free(line);
		i++;
	}
	return (0);
}