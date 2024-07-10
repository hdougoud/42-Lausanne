/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:18:25 by hdougoud          #+#    #+#             */
/*   Updated: 2024/07/10 19:09:24 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char *ft_strdup(int size, char *str)
{
	int i;
	char *strcopy;
	
	i = 0;
	strcopy = malloc(sizeof(char) * size + 1);
	if (strcopy == NULL)
		return (strcopy);
	while (str[i])
	{	
		strcopy[i] = str[i];
		i++;
	}
	strcopy[i] = '\0'; 
	return (strcopy);

}

int ft_strleng(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

struct s_stock_str *ft_strs_to_tab(/*int ac,*/ char **av)
{
	char *strcopy;
	int i;
	int j;
	int size;
	
	i = 1;
	j = 0;
	size = ft_strleng(av[1]);
	strcopy = ft_strdup(size, av[1]);
	printf("%d", size);
	printf("%s", strcopy);
	return (0);
	while(str[i][j])
	{
		
	}
}

int main(/*int ac, char **av*/)
{
	char *av[] = {"Hello", "World", "test"};
	ft_strs_to_tab(av);
	return (0);
}