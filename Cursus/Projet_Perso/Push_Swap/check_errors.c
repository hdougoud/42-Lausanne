/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:37:56 by hdougoud          #+#    #+#             */
/*   Updated: 2024/11/27 10:42:00 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void print_error(void)
{
	ft_printf("Error\n");
}

int	check_args(int argc, char **argv)
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

int	check_duplicate(int argc, char **argv)
{
	int	i;
	int	current_value;
	int position;

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

int main(int argc, char **argv)
{
	int error;
	
	error = check_args(argc, argv);
	if (error == 1)
	{
		print_error();
		return (1);
	}
	else
		printf("digit only\n");
	error = check_duplicate(argc, argv);
	if (error == 1)
	{
		print_error();
		return (1);
	}
	else
		printf("no duplicate\n");
	return (0);
}