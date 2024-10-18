/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:07:08 by hdougoud          #+#    #+#             */
/*   Updated: 2024/06/26 19:12:34 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);

void	ft_putstr(char *str)
{
	while(*str != '\0')
	{	
		write(1, str, 1);
		str ++;
	}
}

int	main(void)
{
	ft_putstr("Hello World");
	return (0);
}