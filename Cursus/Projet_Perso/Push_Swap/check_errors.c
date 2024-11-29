/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:37:56 by hdougoud          #+#    #+#             */
/*   Updated: 2024/11/29 14:07:33 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_args(int argc, char **argv)
{
	int		i;
	int		j;
	long	number;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (ft_isdigit(argv[i][j]) == 0)
				return (1);
			j++;
		}
		if (ft_strlen(argv[i]) > 12)
			return (1);
		number = ft_atol(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

static int	check_duplicate(int argc, char **argv)
{
	int	i;
	int	current_value;
	int	position;

	i = 1;
	while (i < argc)
	{
		position = 1;
		current_value = ft_atoi(argv[i]);
		while (position < argc)
		{
			if (position == i)
				position++;
			if (position >= argc)
				return (0);
			if (ft_atoi(argv[position]) == current_value)
				return (1);
			position++;
		}
		i++;
	}
	return (0);
}

void	check_errors(int argc, char **argv)
{
	int	error;

	error = check_args(argc, argv);
	if (argc <= 1)
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	if (error == 1)
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	error = check_duplicate(argc, argv);
	if (error == 1)
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
}
