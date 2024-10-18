/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:50:27 by hdougoud          #+#    #+#             */
/*   Updated: 2024/06/27 15:47:13 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	b;

	i = 0;
	b = 0;
	while (dest[i])
		i++;
	b = i;
	i = 0;
	while (src[i] && i < nb)
	{
		dest[b] = src[i];
		i++;
		b++;
	}
	dest[b] = '\0';
	return (dest);
}

/*#include <stdio.h>

int main(void)
{
	char dest[11] = "Hello";
	char src[] = "World";
	char *result = ft_strncat(dest, src, 2);
	printf("%s", result);
	return (0);
}*/