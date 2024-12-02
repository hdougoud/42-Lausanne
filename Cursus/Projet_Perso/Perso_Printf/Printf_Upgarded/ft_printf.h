/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:01:44 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/02 17:46:42 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_F
# define PRINT_F

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

size_t	count_int(int nb);
size_t	count_char(char c);
size_t count_pointer(void *p);
size_t	ft_strlen(const char *s);
size_t	count_unsigned_int(unsigned int nb);

#endif