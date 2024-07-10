/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:21:05 by yourlogin         #+#    #+#             */
/*   Updated: 2024/07/10 23:24:06 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_stock_str.h"

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

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	char *strcopy;
	int j;
    int strsize;
	int acsize;
	
	j = 1;
    acsize = 0;
    while (acsize < ac)
    t_stock_str stock;
    {
        strsize = ft_strleng(av[j]);
        strcopy = ft_strdup(strsize, av[j]);
        printf("%d\n", strsize );
        printf("%s\n", strcopy);
        stock.size = strsize;
        stock.str = av[j];
        stock.strcopy = strcopy;
        j++;
        acsize++;
    }
    return (0);
}

int main(/*int ac, char **av*/)
{
	char *av[] = {"nomfichier", "Hello", "World", "test"};
    int ac = 3;
	ft_strs_to_tab(ac, av);
	return (0);
}