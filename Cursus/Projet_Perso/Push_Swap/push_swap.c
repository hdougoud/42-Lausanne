/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:23:05 by hdougoud          #+#    #+#             */
/*   Updated: 2024/11/27 16:34:30 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int **swap(int argc, char *argv[])
// {
// 	int **test;

// 	test = NULL;
// 	return (test);
// }

#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	check_errors(argc, argv);
	while (i < argc)
	{
		printf("%s\n", argv[i]);
		i++;
	}
	printf("%d\n", argc);
}
