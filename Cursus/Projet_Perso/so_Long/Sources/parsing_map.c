/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:13:02 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/30 15:47:40 by hdougoud         ###   ########.fr       */
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

void	check_path_map(t_minilx *mlx)
{
	int	collectible;
	int	exit;

	check_map_border(mlx);
	collectible = 0;
	exit = 0;
	
	
}
// ADD VERIF FOR ENEMY