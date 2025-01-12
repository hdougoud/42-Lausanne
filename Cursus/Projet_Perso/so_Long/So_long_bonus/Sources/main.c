/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:34:51 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/12 13:27:51 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_death(t_minilx *mlx)
{
	int x;
	int y;

	x = mlx->player_pos_x;
	y = mlx->player_pos_y;
	if (mlx->sprites->player->dth_current_frame >= 7)
	{
		ft_put_image(mlx, mlx->sprites->player->dth_frames[7], x, y);
		return ;
	}
	ft_put_image(mlx, mlx->sprites->player->dth_frames[mlx->sprites->player->dth_current_frame], x, y);
	if (mlx->delayed_frame >= 4)
	{
		mlx->delayed_frame = 0;
		mlx->sprites->player->dth_current_frame++;
	}
}

int main(int argc, char **argv) //SEGFAULT direct clean exit
{
	t_minilx	mlx;

	init_minilx(&mlx);
	if (argc != 2)
		show_error(&mlx, WRONG_ARGUMENTS);
	init_map(&mlx, argv[1]);
	check_path_map(&mlx);
	mlx.map->map_enemy = create_enemy_map(&mlx, mlx.map->map_tab);
	mlx_key_hook(mlx.win, hook_keyboard, &mlx);
	mlx_hook(mlx.win, 17, 0, windows_closed, &mlx);
	mlx_loop_hook(mlx.mlx, next_frame, &mlx);
	mlx_loop(mlx.mlx);
}
