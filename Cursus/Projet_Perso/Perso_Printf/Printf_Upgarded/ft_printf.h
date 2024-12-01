/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:01:44 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/02 00:33:02 by hdougoud         ###   ########.fr       */
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
size_t	ft_strlen(const char *s);

#endif