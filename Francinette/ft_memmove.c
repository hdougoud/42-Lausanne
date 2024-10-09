/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:21:28 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/09 11:57:59 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NO FINISHED
#include "libft.h" //no used

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	unsigned char	*udst;
	unsigned char	*usrc;

	udst = (unsigned char *) dst;
	usrc = (unsigned char *) src;
	i = 0;
	if (src < dst) //Avoid overlap
	{
		while (len > 1)
		{
			udst[len] = usrc[len];
			len--;
		}
	}
	return (dst);
}

//int main(void)
//{
//	char s[] = "Hello World";
//	char se[] = "tesst funct";
//	ft_memmove(se, s , 5);
//	printf("%s\n", se);
//}

	// while (len > i)
	// {
		// udst[i] = usrc[i];         Possiblement inutile
		// i++;
	// }