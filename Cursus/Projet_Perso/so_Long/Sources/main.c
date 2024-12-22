/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:34:51 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/22 02:03:36 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_minilx	mlx;
	
	if (argc != 2)
		show_error(WRONG_ARGUMENTS);
	mlx.mouvement = 0;
	init_mlx_and_map(&mlx, argv[1]);
	mlx_key_hook(mlx.win, hook_keyboard, &mlx);
	mlx_loop(mlx.mlx);
}
