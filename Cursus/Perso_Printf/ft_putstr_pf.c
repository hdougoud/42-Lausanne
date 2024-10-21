/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:50:07 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/21 10:04:15 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr_pf(char *s)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
	while (s[i])
	{
		ft_putchar_pf(s[i]);
		i++;
		value++;
	}
	return (value);
}