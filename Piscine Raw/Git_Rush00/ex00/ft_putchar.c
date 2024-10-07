/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:55:37 by hdougoud          #+#    #+#             */
/*   Updated: 2024/06/23 16:55:47 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_message(const char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		write(1, &msg[i], 1);
		i++;
	}
}
