/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:34:51 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/07 15:38:37 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int next_frame(t_minilx *mlx)
{
	mlx->frame_count++;
	if (mlx->frame_count >= 5000)
	{
		mlx->sprites->player->current_frame++;
		ft_put_image(mlx->mlx, mlx->sprites->empty->name, mlx->player_pos_x, mlx->player_pos_y);
		ft_put_image(mlx->mlx, mlx->sprites->player->frames[mlx->sprites->player->current_frame], mlx->player_pos_x, mlx->player_pos_y);
		if (mlx->sprites->player->current_frame >= 7)
			mlx->sprites->player->current_frame = 0;
		mlx->frame_count = 0;
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
	mlx_loop_hook(mlx.mlx, next_frame, &mlx);
	mlx_loop(mlx.mlx);
}
