/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:13:02 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/05 20:13:02 by hdougoud         ###   ########.fr       */
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

void	path_is_valide(int **map, int *collectable, int *exit, int x, int y)
{
	if (map[y][x] == 'C')
		*collectable++;
	if (map[y][x] == 'E')
		*exit++;
	if (map[y][x] != '1' && map[y][x] != 'V')
		map[y][x] = 'V';
	path_is_valide(map, collectable, exit, x + 1, y);
	path_is_valide(map, collectable, exit, x, y + 1);
	path_is_valide(map, collectable, exit, x - 1, y);
	path_is_valide(map, collectable, exit, x, y - 1);
	return ;
}

void	check_path_map(t_minilx *mlx)
{
	int exit;
	int collectable;
	int **map;
	
	check_map_border(mlx);
	collectable = 0;
	exit = 0;
	map = mlx->map->map_tab;
	path_is_valide(map, &collectable, &exit, mlx->player_pos_x, mlx->player_pos_y);
	if (exit != mlx->map->exit_nb && collectable != mlx->map->collectable_nb)
		show_error(mlx, WRONG_MAP_PATH);
}

// ADD VERIF FOR ENEMY