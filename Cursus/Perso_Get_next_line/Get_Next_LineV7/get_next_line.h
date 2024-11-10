/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:54:22 by hdougoud          #+#    #+#             */
/*   Updated: 2024/11/10 15:16:46 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif  

# include <stdlib.h>
# include <unistd.h>

#include <stdio.h>

char	*get_next_line(int fd);
char	*add_back_buffer(char *line, char *buff, int buff_len);
int		ft_strlen(char *str);

#endif