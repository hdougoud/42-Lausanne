/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:56:45 by hdougoud          #+#    #+#             */
/*   Updated: 2024/07/10 14:46:51 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_inter(char *str1, char *str2)
{
	int i = 0;
	int j = 0;
	int check = 0;
	int k = 0;

	while (str1[i])
	{
		if (str2[j] == '\0')
		{
			j = 0;
			i++;
			check = 1;
		}
		if (check == 1)
		{
			k = i;
			while (k > 0)
			{
				if (str1[i] == str1[k - 1])
				{
					i++;
					k = i;
				}
				k--;
			}
			check = 0;
		}
		if (str1[i] == str2[j])
		{
			write(1, &str1[i], 1);
			i++;
			j = 0 - 1;
			check = 1;
		}
		j++;
	}
	write (1, "\n", 1);
}

int main(void)
{
	char *str1 = "";
	char *str2 = "abc";
	ft_inter(str1, str2);

	/*char *str1 = "HalleittHgg";
	char *str2 = "Halloe HWorld";
	ft_inter(str1, str2);*/
	return (0);
}