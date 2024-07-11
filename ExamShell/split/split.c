/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:46:32 by hdougoud          #+#    #+#             */
/*   Updated: 2024/07/11 19:05:42 by hdougoud         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char *ft_split(char *str)
{
	int word = 1;
	int i = 0;

	while (str[i++])
	{
		if(str[i] == (' ' || 9 || 10)) //&& ((str[i + 1] >= 'A' && str[i + 1] <= 'Z') || (str[i + 1] >= 'a' && str[i + 1] <= 'z')))
			word++;
	}
	printf("%d", word);
	return ("Hello");
}

int main(void)
{
	char *string = "this is		as \n string test ";
	ft_split(string);
	return (0);
}