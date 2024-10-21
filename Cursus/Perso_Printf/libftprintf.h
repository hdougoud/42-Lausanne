/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:48:44 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/21 16:13:51 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdio.h>


#include <stdarg.h>
#include <unistd.h>


int	ft_putchar_pf(char c);
int	ft_putstr_pf(char *s);
int	ft_int_putnbr_pf(int n, int *value);
int	ft_unsigned_putnbr_pf(unsigned int n, int *value);
int	ft_print_pointer(unsigned long *s);

#endif