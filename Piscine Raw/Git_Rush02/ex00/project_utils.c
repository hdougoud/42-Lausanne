/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liwirth <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:19:58 by liwirth           #+#    #+#             */
/*   Updated: 2024/07/07 14:29:16 by liwirth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/project_utils.h"

char	*process_numbers(char **line)
{
	char	*start;
	char	tmp;
	char	*result;

	*start = *line;
	while (**line >= '0' && **line <= '9')
		(*line)++;
	if (*line == start)
		return (NULL);
	tmp = **line;
	**line = '\0';
	*result = strdup(start);
	**line = tmp;
	return (result);
}

int	skip_spaces(char **line)
{
	while (**line == ' ')
		(*line)++;
	return (1);
}

int	skip_colon(char **line)
{
	if (**line == ':')
	{
		(*line)++;
		return (1);
	}
	return (0);
}

char	*process_printables(char **line)
{
	char	*start;
	char	tmp;
	char	*result;

	*start = *line;
	while (**line >= 32 && **line <= 126)
		(*line)++;
	if (*line == start)
		return (NULL);
	tmp = **line;
	**line = '\0';
	*result = strdup(start);
	**line = tmp;
	return (result);
}
