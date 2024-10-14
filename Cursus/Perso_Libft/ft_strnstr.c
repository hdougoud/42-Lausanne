/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:13:16 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/14 17:15:13 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str;
	char	*sch;
	unsigned int		i;
	unsigned int		count;

	str = (char *) haystack;
	sch = (char *) needle;
	count = 0;
	i = 0;
	if (ft_strlen(needle) == 0)
		return (str);
	while (len > i && str[i] != '\0')
	{
		if (str[i] == sch[count])
		{
			count++;
		}
		else
			count = 0;
		i++;
		if (count == ft_strlen(needle))
			return (str = str + (i - count));
	}
	return (NULL);
}

//int main(void)
//{
//    char *s1 = "lorem ipsum dolor sit amet";
//	char *s2 = "ipsum";
//    size_t max = strlen(s1);
//    printf("%s\n", strnstr(s1, s2, 9));
//    printf("%s\n", ft_strnstr(s1, s2, 9));
//    return 0;
//}