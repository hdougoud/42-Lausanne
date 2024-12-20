/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:56:02 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/20 11:29:22 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*strdup_map_line(const char *s1)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!ptr)
		show_error(malloc_error);
	while (s1[i])
	{
		if (s1[i] == '\n')
			i++;
		else
		{	
			ptr[i] = s1[i];
			i++;
		}
	}
	ptr[i] = '\0';
	return (ptr);
}