/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:30:19 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/02 14:28:14 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < dstsize)
	{
		dst[i + dstsize] = src[i];
		i++;
	}
	dst[i + dstsize] = '\0';
	return (ft_strlen(dst));
}

//int main(void)
//{
//	char s[] = "Hello";
//	char se[] = "World";
//	printf("%zu\n", ft_strlcat(s, se, 3));
//	return (0);
//}