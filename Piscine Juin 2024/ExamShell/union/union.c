/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:39:51 by hdougoud          #+#    #+#             */
/*   Updated: 2024/07/11 17:26:37 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/*int ft_printed(int i, char *str1, char *str2)
{
	
}*/

void ft_union(char **argv)
{
	int first_leng;
	int i = 0;
	int j = 0;
	int check = 0;
	int leng = 0;
	int first_leng = 0;

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
	first_leng = i;
	j = i;
	i = 0;
	while (str2[i])
	{
		check = i;
		while (check > 1)
		{
			while(j > 0)
			{
				if (str1[j] == str2[i])
				{
					i++;
					j = first_leng;
				}
				j--;
			}
			j = 0;
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
	write(1, "\n", 1);
}


int main (int argc, char **argv)
{
	/*char *str1 = "zpadinton";//ddf6vewg64f
	char *str2 = "paqefwtdjetyiytjneytjoeyjnejeyj";*/
	ft_union(argv)
	return (0);
}