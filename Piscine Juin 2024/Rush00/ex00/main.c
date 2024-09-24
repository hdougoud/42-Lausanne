/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:56:04 by hdougoud          #+#    #+#             */
/*   Updated: 2024/06/23 16:56:10 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);
void	print_message(const char *msg);

int	is_valid_digit_string(const char *str)
{
	int	i;

	i = 0;
	if (str[0] == '0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	string_to_int(const char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int	process_arguments(int argc, char **argv, int *x, int *y)
{
	if (argc == 3)
	{
		if (!is_valid_digit_string(argv[1]) || !is_valid_digit_string(argv[2]))
		{
			print_message("Error: arguments must be positive integers.\n");
			return (1);
		}
		*x = string_to_int(argv[1]);
		*y = string_to_int(argv[2]);
		if (*x <= 0 || *y <= 0)
		{
			print_message("Error: dimensions must be positive integers.\n");
			return (1);
		}
	}
	else if (argc != 1)
	{
		print_message("Usage: ./my_program [width] [height]\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	x;
	int	y;

	x = 5;
	y = 3;
	if (process_arguments(argc, argv, &x, &y) != 0)
		return (1);
	rush(x, y);
	return (0);
}
