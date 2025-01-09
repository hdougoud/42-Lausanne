/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_chest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:16:56 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/09 17:24:48 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void open_chest(t_minilx *mlx)
{
	if (mlx->sprites->chest->is_animating == 1)
		return ;
	if (mlx->map->map_tab[mlx->player_pos_y][mlx->player_pos_x] == 'C')
	{
		mlx->map->map_tab[mlx->player_pos_y][mlx->player_pos_x] = 'O';
		mlx->sprites->chest->posx = mlx->player_pos_x;
		mlx->sprites->chest->posy = mlx->player_pos_y;
		mlx->sprites->chest->is_animating = 1;
		mlx->map->collectable_nb--;
	}
	else if (mlx->map->map_tab[mlx->player_pos_y][mlx->player_pos_x - 1] == 'C')
	{
		mlx->map->map_tab[mlx->player_pos_y][mlx->player_pos_x - 1] = 'O';
		mlx->sprites->chest->posx = mlx->player_pos_x -1;
		mlx->sprites->chest->posy = mlx->player_pos_y;
		mlx->sprites->chest->is_animating = 1;
		mlx->map->collectable_nb--;
	}
}
