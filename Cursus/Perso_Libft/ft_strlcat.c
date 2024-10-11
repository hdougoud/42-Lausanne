/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:30:19 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/11 14:40:35 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	dst_len;

	i = 0;
	dst_len = (ft_strlen(dst));
	if (ft_strlen(dst) >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (i + dst_len < dstsize - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (ft_strlen(src) + dst_len);
}

//int main(void)
//{
//	char *str = "the cake is a lie !\0I'm hidden lol\r\n";
//	char buff1[0xF00] = "there is no stars in the sky";
//	char buff2[0xF00] = "there is no stars in the sky";
//	size_t nb = (ft_strlen("there is no stars in the skythe cake is a lie !\0I'm hidden lol\r\n") - 6);
//	printf("ft_strlcat	%zu\n", ft_strlcat(buff1, str, nb));
//	printf("%s\n", buff1);
//	printf("strlcat		%zu\n", strlcat(buff2, str, nb));
//	printf("%s\n", buff2);
//}