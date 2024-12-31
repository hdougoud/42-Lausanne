/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:13:02 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/31 01:25:10 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO : BFS (Breadth-First Search)
#include "so_long.h"

static void check_map_border(t_minilx *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (mlx->map->map_tab[y][x])
	{
		if (mlx->map->map_tab[y][x] != '1')
			show_error(mlx, WRONG_MAP_PATERN);
		x++;
	}
	while (++y < mlx->map->height - 1)
	{
		if ((mlx->map->map_tab[y][0] != '1') 
				|| (mlx->map->map_tab[y][mlx->map->width - 1] != '1'))
			show_error(mlx, WRONG_MAP_PATERN);
	}
	x = 0;
	while (mlx->map->map_tab[y][x])
	{
		if (mlx->map->map_tab[y][x] != '1')
			show_error(mlx, WRONG_MAP_PATERN);
		x++;
	}
}

void	path_is_valide(t_minilx *mlx, int collectable, int exit)
{
	if (mlx->map->map_tab[mlx->player_pos_y][mlx->player_pos_x])
		return ;
}

void	check_path_map(t_minilx *mlx)
{
	int exit;
	int collectable;
	
	check_map_border(mlx);
	collectable = 0;
	exit = 0;
}

// ADD VERIF FOR ENEMY