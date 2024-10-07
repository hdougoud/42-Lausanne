/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:27:39 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/02 11:01:16 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int				i;
	unsigned char	*udst;
	unsigned char	*usrc;

	udst = (unsigned char *) dst;
	usrc = (unsigned char *) src;
	i = 0;
	while (n > i)
	{
		udst[i] = usrc[i];
		i++;
	}
	return (dst);
}

//int main(void)
//{
//	char s[] = "Hello World How Are You";
//	char se[] = "bjbjbjsbsnvsdndn kldf;lse";
//	printf("%s\n", se);
//	ft_memcpy(se, s, 20);
//	printf("%s\n", se);
//}