/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:34:51 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/06 12:48:55 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv) //SEGFAULT direct clean exit
{
	t_minilx	mlx;
	
	init_minilx(&mlx);
	if (argc != 2)
		show_error(&mlx, WRONG_ARGUMENTS);
	init_map(&mlx, argv[1]);
	check_path_map(&mlx);
	mlx_key_hook(mlx.win, hook_keyboard, &mlx);
	mlx_hook(mlx.win, 17, 0, windows_closed, &mlx);
	mlx_loop(mlx.mlx);
}
