/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:43:19 by hdougoud          #+#    #+#             */
/*   Updated: 2024/11/01 15:45:29 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void *add_back(char *buff, t_line **current_line)
{
	t_line *last_node;
	t_line *new_node;

	last_node = *current_line; // double

	new_node = malloc(sizeof(t_line));
	if (new_node == NULL)
		return (NULL);
	new_node->content = buff;
    new_node->next = NULL;
		
	if (*current_line == NULL)
	{
		*current_line = new_node;
		return (0);
	}
	
	last_node = *current_line;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = new_node;
	return (0);
}
char *combine_node(t_line **current_line)
{
	int		i;
	int		j;
	int		count_line;
	t_line	*count_list;
	t_line	*add_node;
	char	*combined_line;

	count_line = 0;
	count_list = *current_line;
	add_node = *current_line;
	while (count_list != NULL)
	{
		i = 0;
		while(i < BUFFER_SIZE && count_list->content[i++] != '\n')
			count_line++;
		count_list = count_list->next;
	}
	combined_line = malloc(sizeof(char) * (count_line + 1));
	j = 0;
	while (add_node != NULL)
	{
		i = 0;
		while(i < BUFFER_SIZE && add_node->content[i] != '\n')
		{
			combined_line[j] = add_node->content[i];
			i++;
			j++;
		}
		add_node = add_node->next;
	}
	combined_line[j] = '\0';
	return (combined_line);
}
