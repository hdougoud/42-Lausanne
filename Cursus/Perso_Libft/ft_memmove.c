/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:21:28 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/10 21:50:31 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*udst;
	unsigned char	*usrc;

	udst = (unsigned char *) dst;
	usrc = (unsigned char *) src;
	while (len >= 1)
	{
		udst[len] = usrc[len];
		len--;
	}
	return (dst);
}

//int main(void)
//{
//	char s[] = "Hello World";
//	char se[] = "AAAAAAAAAAA";
//	printf("%s\n", memmove(se, s , 3));
//	printf("%s\n", ft_memmove(se, s , 3));
//	
//}