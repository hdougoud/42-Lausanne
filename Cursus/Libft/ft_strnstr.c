/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:13:16 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/03 14:12:06 by hdougoud         ###   ########.fr       */
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
	if (needle == 0)
		return (str);
	nlen = ft_strlen(needle);
	while (len > 1 && str[i] != '\0')
	{
		if (str[i] == sch[count])
		{
			count++;
		}
		i++;
		len--;
		if (count == nlen)
			return (str = str + (i - count));
	}
	return (0);
}

//int main(void)
//{
//	char	sh[] = "Hello this is a test";
//	char	se[] = "is";
//	printf("%s\n", ft_strnstr(sh, se, 50));
//	return (0);
//}