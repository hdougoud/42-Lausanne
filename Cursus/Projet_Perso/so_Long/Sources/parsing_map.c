/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:13:02 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/29 21:49:48 by hdougoud         ###   ########.fr       */
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
	int	x;
	int	y;

	x = mlx->player_pos_x;
	y = mlx->player_pos_y;
	check_map_border(mlx);
	mlx->map->collectable_nb = 1;
	printf("pos X %d\n", x);
	printf("pos Y %d\n", y);
	while (mlx->map->map_tab[y][x])
		x++;
	printf("largeur %d\n", mlx->map->width);
	printf("hauteur %d\n", mlx->map->height);
}