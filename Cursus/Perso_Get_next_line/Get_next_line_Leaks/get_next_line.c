/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:40:34 by hdougoud          #+#    #+#             */
/*   Updated: 2024/11/13 15:10:54 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == 0)
		return (NULL);
	i = 0;
	if (s1 != NULL)
	{	
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		free(s1);
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s2);
	return (str);
}

int	ft_strrchr(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return(1);
	return (0);
}


char	*get_line(int fd, int bytes_read, char *current_line)
{
	char		*buff;
	
	while(1)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (buff);
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(current_line), NULL);
		if (bytes_read == 0)
			break ;
		buff[bytes_read] = '\0';
		current_line = ft_strjoin(current_line, buff);
		if (!current_line)
			return (NULL);
		if (ft_strrchr(buff) == 1)
			break ;
	}
	return (current_line);
}

char	*add_stash(char *line, int new_line)
{
	char	*new_stash;
	int		i;
	
	i = 0;
	new_stash = malloc(sizeof(char) * ft_strlen(line) - new_line + 1);
	if (!new_stash)
		return (NULL);
	while(line[new_line])
		new_stash[i++] = line[new_line++];
	new_stash[i] = '\0';
	return (new_stash);
}

char	*manage_stash(char *line, char **stash)
{
	char	*complete_line;
	int		new_line;
	int		i;
	
	new_line = 0;
	while (line[new_line] && line[new_line] != '\n')
		new_line++;
	if (line[new_line] == '\0')
	{
		*stash = NULL;
		return (line);
	}
	new_line++;
	complete_line =malloc(sizeof(char) * (new_line + 1));
	if (!complete_line)
		return (NULL);
	i = -1;
	while (++i < new_line)
		complete_line[i] = line[i];
	complete_line[i] = '\0';
	*stash = add_stash(line, new_line);
	if (!*stash)
		return (NULL);
	return (free(line), complete_line);
}

char	*get_next_line(int fd)
{
	int			byte_read;
	char		*line;
	static char *stash; 
	
	byte_read = 0;
	line = NULL;
	if (stash)
	line = ft_strjoin(line, stash);
	line = get_line(fd, byte_read, line);
	if (!line)
		return (NULL);
	line = manage_stash(line, &stash);
	return (line);
}

// #include <fcntl.h>

// int main(void)
// {
// 	int i = 0;
//     int fd = open("test.txt", O_RDONLY);
// 	char *line;

// 	if (fd == -1)
// 	{
// 		printf("Open failed\n");
// 		return (1);
// 	}    
// 	while (i < 15)
// 	{
// 		line = get_next_line(fd);
// 		if (line != NULL)
// 	    	printf("Result %s", line);
// 		else 
// 			printf("Result %s\n", line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }
