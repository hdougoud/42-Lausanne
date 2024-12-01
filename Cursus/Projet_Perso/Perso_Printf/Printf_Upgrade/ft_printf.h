/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:07:11 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/01 16:50:41 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int	putstr_pf(char *s, int value);
int	putnbr_pf(int n, int *value);
int	unsigned_putnbr_pf(unsigned int n, int *value);
int	print_hex_pf(unsigned int un, int *value, char param);
int	write_pointer_pf(unsigned long un, int *value);

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

char	*addchar_pf(char *s1, char c, unsigned int str_len);
char	*ft_strjoin(char const *s1, char const *s2);

void	safe_free(char **ptr);

#endif