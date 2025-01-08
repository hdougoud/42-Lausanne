/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:35:40 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/08 23:44:08 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_enemy_map(t_minilx *mlx, char **map)
{
	int		i;
	int		j;
	char	**copyed_map;

	j = 0;
	copyed_map = malloc(sizeof(char *) * (mlx->map->height + 1));
	if (!copyed_map)
		show_error(mlx, MALLOC_ERROR);
	while (map[j])
	{
		i = -1;
		copyed_map[j] = malloc(sizeof(char) * (mlx->map->width + 1));
		if (!copyed_map[j])
		{
			clear_map(copyed_map, j);
			show_error(mlx, MALLOC_ERROR);
		}
		while (map[j][++i])
		{
			if (map[j][i] == '1')
				copyed_map[j][i] = '1';
			else if (map[j][i] == 'B')
				copyed_map[j][i] = 'B';
			else
				copyed_map[j][i] = '0';
		}
		copyed_map[j][i] = '\0';
		j++;
	}
	copyed_map[j] = NULL;
	return (copyed_map);
	printf("%s\n", "map_copyed");

}

static void move_enemy(t_minilx *mlx, int x, int y)
{
	printf("%s\n", "move enemy start");
	ft_put_image(mlx, mlx->sprites->empty->name, x, y);
	mlx->map->map_enemy_copy[y][x] = '0';
	x += 1;
	mlx->map->map_enemy_copy[y][x] = 'B';
	ft_put_image(mlx, mlx->sprites->empty->name, x, y);
	ft_put_image(mlx, mlx->sprites->enemy->frames[0], x, y);
}

void find_enemy(t_minilx *mlx)
{
	int height;
	int width;

	printf("%s\n", "find enemy start");
	height = 0;
	mlx->map->map_enemy_copy = create_enemy_map(mlx, mlx->map->map_enemy);
	
	while (mlx->map->map_enemy[height])
	{
		width = 0;
		while (mlx->map->map_enemy[height][width])
		{
			if (mlx->map->map_enemy[height][width] == 'B')
				move_enemy(mlx, width, height);
			width++;
		}
		height++;
	}
	clear_map(mlx->map->map_enemy, mlx->map->height);
	mlx->map->map_enemy = mlx->map->map_enemy_copy;
	mlx->map->map_enemy_copy = NULL;
}
