/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:34:51 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/06 16:26:18 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int next_frame(t_minilx *mlx)
{
	static int	counter;

	counter++;
	if (counter >= 7000)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->sprites->empty->name,
		192, 128);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->sprites->chest->frames[mlx->sprites->chest->current_frame],
		192, 128);
		mlx->sprites->chest->current_frame++;
		if (mlx->sprites->chest->current_frame == 3)
			mlx->sprites->chest->current_frame = 0;
		if ((mlx->player_pos_x * 64) == 192 && (mlx->player_pos_y * 64) == 128)
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->sprites->player->name,
			192, 128);
		counter = 0;
	}
	return (0);
}

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

	mlx.sprites->chest = malloc(sizeof(t_chest));
	if (!mlx.sprites->chest)
		show_error(&mlx, MALLOC_ERROR);
	
	mlx.sprites->chest->current_frame = 0;
	
	mlx.sprites->chest->frames[0] = mlx_xpm_file_to_image(mlx.mlx, "sprites/XPM/Chest_1.xpm",
		&mlx.sprites->chest->x, &mlx.sprites->chest->y);
	mlx.sprites->chest->frames[1] = mlx_xpm_file_to_image(mlx.mlx, "sprites/XPM/Chest_2.xpm",
		&mlx.sprites->chest->x, &mlx.sprites->chest->y);
	mlx.sprites->chest->frames[2] = mlx_xpm_file_to_image(mlx.mlx, "sprites/XPM/Chest_3.xpm",
		&mlx.sprites->chest->x, &mlx.sprites->chest->y);
	mlx.sprites->chest->frames[3] = mlx_xpm_file_to_image(mlx.mlx, "sprites/XPM/Chest_4.xpm",
		&mlx.sprites->chest->x, &mlx.sprites->chest->y);
	
	mlx_loop_hook(mlx.mlx, next_frame, &mlx);
	
	mlx_loop(mlx.mlx);
}
