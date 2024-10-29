/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:43:11 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/29 10:52:00 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif  

#include <stdlib.h>
#include <unistd.h>


#include <stdio.h>


char	*get_next_line(int fd);

typedef struct s_line
{
	char *content;
	struct s_line *next;
}	t_line;

#endif