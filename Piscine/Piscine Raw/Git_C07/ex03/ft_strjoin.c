/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:46:06 by hdougoud          #+#    #+#             */
/*   Updated: 2024/07/09 14:55:46 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include<stdio.h>

int	ft_total_leng(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	total_leng;
	int	sep_number;
	int	sep_leng;

	j = 0;
	total_leng = 0;
	sep_leng = 0;
	sep_number = 0;
	while (size > 0)
	{
		i = 0;
		while (strs[j][++i])
			total_leng++;
		size--;
		sep_number++;
		j++;
	}
	i = 0 - 1;
	while (sep[++i])
		sep_leng ++;
	sep_leng = (sep_number - 1) * sep_leng;
	total_leng = total_leng + sep_leng;
	return (total_leng);
}

char	*ft_combine(int size, char **strs, char *sep, char *start)
{
	int		i;
	int		j;
	int		str_leng;
	int		sep_leng;

	j = 0;
	str_leng = 0;
	sep_leng = 0;
	while (size > 0)
	{
		i = 0;
		while (strs[j][i])
			start[str_leng++] = strs[j][i++];
		sep_leng = 0;
		j++;
		size--;
		if (size > 0)
		{
			while (sep[sep_leng])
				start[str_leng++] = sep[sep_leng++];
		}
	}
	str_leng++;
	start[str_leng] = '\0';
	return (start);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_leng;
	char	*str;

	if(size == 0)
	{
		str = malloc(sizeof(char) * size)
		return (str)
	}
	total_leng = ft_total_leng(size, strs, sep);
	str = malloc(sizeof(char) * total_leng + 1);
	if (total_leng == '\0')
		return (NULL);
	str = ft_combine(size, strs, sep, str);
	return (str);
}

/*int	main(void)
{
	char *tab[] = {"mot1, "mot2", "mot3", "mot4"};
	char *sep =	" esp ";
	printf("%s", ft_strjoin(4, tab, sep));
	return (0);
}*/