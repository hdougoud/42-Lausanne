/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayden <hayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:07:11 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/27 18:13:09 by hayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>


# include <stdio.h>

int	ft_printf(const char *format, ...);
int	putchar_pf(char c, int value);
int	putstr_pf(char *s, int value);
int	int_putnbr_pf(int n, int *value);
int	unsigned_putnbr_pf(unsigned int n, int *value);
int	hexlow_putnbr_pf(int n, int *value);
int	hexup_putnbr_pf(int n, int *value);

#endif