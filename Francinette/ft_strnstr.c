/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:13:16 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/10 16:27:34 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str;
	char	*sch;
	int		i;
	int		nlen;
	int		count;

	str = (char *) haystack;
	sch = (char *) needle;
	count = 0;
	i = 0;
	if (ft_strlen(needle) == 0)
		return (str);
	nlen = ft_strlen(needle);
	while (len > 0  && str[i] != '\0')
	{
		if (str[i] == sch[count])
		{
			count++;
		}
		else 
			count = 0;
		i++;
		len--;
		if (count == nlen)
			return (str = str + (i - count));
	}
	return (0);
}

//int main(void)
//{
//    char *s1 = "lorem ipsum dolor sit amet";
//	char *s2 = "ipsumm";
//    size_t max = strlen(s1);
//    printf("%s\n", strnstr(s1, s2, 30));
//    printf("%s\n", ft_strnstr(s1, s2, 30));
//    return 0;
//}