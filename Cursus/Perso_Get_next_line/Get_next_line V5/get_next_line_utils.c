/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:56:52 by lausanne42        #+#    #+#             */
/*   Updated: 2024/11/05 15:45:08 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*add_back_buffer(char *line, char *buff, int buff_len)
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