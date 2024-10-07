/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:31:40 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/07 14:08:47 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		end;
	int		i;

	i = 0;
	end = 0;
	while (*set)
	{
		if (ft_strchr(set, *s1))
			s1++;
		if (ft_strrchr(set, s1[3]))
			end++;
		else
			set++;
	}
	str = malloc(sizeof(char) * (ft_strlen(s1) - end + 1));
	while (i < (ft_strlen(s1) - end))
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str); //ftstrdup
}

int main(void)
{
	char s[] = "123A";
	char c[] = "A";
	printf("%s\n", ft_strtrim(s, c));
}
