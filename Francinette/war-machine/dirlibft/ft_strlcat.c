/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:30:19 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/09 15:25:49 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dst > src)
		return(ft_strlen(src) + dstsize);
	while (src[i] || i < dstsize)
	{
		dst[i + dstsize] = src[i];
		i++;
	}
	dst[i + dstsize] = '\0';
	return (ft_strlen(dst));

}

//int main(void)
//{
//	char *str = "the cake is a lie !\0I'm hidden lol\r\n";
//	char buff1[0xF00] = "there is no stars in the sky";
//	char buff2[0xF00] = "there is no stars in the sky";
//	size_t max = strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4;
//
//	__builtin___strlcat_chk (buff1, str, max, __builtin_object_size (buff1, 2 > 1 ? 1 : 0));
//	ft_strlcat(buff2, str, max);
//	if (!strcmp(buff1, buff2))
//		printf("succes");
//	printf("Faild");
//
//	char s[] = "the cake is a lie !\0I'm hidden lol\r\no";
//	char se[] = "here is no stars in the sky";
//	size_t max = ft_strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4;
//	printf("%zu\n", ft_strlcat(s, se, max));
//	return (0);
//}