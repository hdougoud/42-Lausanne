/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:40:34 by hdougoud          #+#    #+#             */
/*   Updated: 2024/11/13 00:49:09 by hdougoud         ###   ########.fr       */
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

// char	*manage_stash(char *line, char **stash)
// {
// 	int	new_line;
// 	int	i;

// 	i = 0;
// 	if (*stash)
// 	{
// 		line = ft_strjoin(*stash, line);
// 		//free(*stash);
// 		if (!line)
// 			return (NULL);
// 	}
// 	while(line[i] && line[i] != '\n')
// 		i++;
// 	if (line[i] == '\n')
// 	{
// 		i++;
// 		new_line = i;
// 		while(line[i])
// 			i++;
// 		*stash = malloc(sizeof(char) * (i - new_line) + 1);
// 		if (!*stash)
// 			return (NULL);
// 		i = 0;
// 		while(line[i])
// 			(*stash)[i++] = line[new_line++];
// 		(*stash)[i] = '\0';
// 	}
// 	line[new_line] = '\0';	//TODO ajouter la stash au debut si elle existe et 
// 	return (line);				//modifier celle si en fonction du reste de la ligne
// }

char	*get_line(int fd, char *current_line, char **stash)
{
	int			byte_read;
	char		buff[BUFFER_SIZE + 1];
	
	while(1)
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read == -1)
			return (NULL);
		if (byte_read == 0)
			break;
		buff[byte_read] = '\0';
		current_line = ft_strjoin(current_line, buff);
		if (!current_line)
			return (NULL);
		if (ft_strrchr(buff) == 1)
			break;
	}
	//if (byte_read > 0)
		//current_line = manage_stash(current_line, stash);
		
		//remplacer manage_stash par une foxntion qui ajoute seulement le buffer au debit se la ligne
		
	return (current_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;
	
	line = NULL;
	line = get_line(fd, line, &stash);
	// ajouter fonction recuperer le \n et ajouter a la stash
	return (line);
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
	while (i < 3)
	{
		line =  get_next_line(fd);
	    printf("%s\n", line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
