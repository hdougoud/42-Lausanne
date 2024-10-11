/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:30:19 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/11 11:18:48 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	dst_len;

	i = 0;
	dst_len =  (ft_strlen(dst));
	if (dst > src)
		return(ft_strlen(src) + dstsize);
	while (src[i] || i < dstsize)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[i + dstsize] = '\0';
	return (ft_strlen(dst));

}

int main(void)
{
	char dst[200] = "World";
	char src[] = "Hello";
	printf("ft_strlcat	%zu\n", ft_strlcat(dst, src, 11));
	printf("%s\n", dst);
	char dst1[200] = "World";
	char src1[] = "Hello";
	printf("strlcat		%zu\n", strlcat(dst1, src1, 11));
	printf("%s\n", dst1);
}