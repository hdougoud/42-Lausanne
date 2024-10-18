/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:48:44 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/18 16:13:56 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdio.h>


#include <stdarg.h>
#include <unistd.h>


void	ft_putchar_pf(char c, int fd);
void	ft_putstr_pf(char *s, int fd);
void	ft_putnbr_pf (int n, int fd);

#endif