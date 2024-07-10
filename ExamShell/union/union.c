/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:39:51 by hdougoud          #+#    #+#             */
/*   Updated: 2024/07/10 16:24:52 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/*int ft_printed(int i, char *str1, char *str2)
{
	
}*/

void ft_union(char *str1, char *str2)
{
	int i = 0;
	int check = 0;
	int leng = 0;

	while (str1[leng])
		leng++;
	while (str1[i])
	{
		check = i;
		while (check > 1)
		{
			if(str1[i] == str1[check - 1])
			{
				i++;
				check = i;
			}
			check--;		
		}
		write(1, &str1[i], 1);
		i++;
	}
	i = 0;
	while (str2[i])
	{
		check = i;
		while (check > 1)
		{
			if (str1[i] == str2[check - 1] && leng >= i)
			{
				i++;
				check = i;
			}
			if (str2[i] == str2[check - 1])
			{
				i++;
				check = i;
			}
			check--;
		}
		write(1, &str2[i], 1);
		i++;
	}
	
}


int main (void)
{
	char *str1 = "zpadinton";//ddf6vewg64f
	char *str2 = "paqefwtdjetyiytjneytjoeyjnejeyj";
	ft_union(str1, str2);
	return (0);
}