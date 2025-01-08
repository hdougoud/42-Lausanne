/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:35:40 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/08 23:16:27 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void create_enemy_map(t_minilx *mlx)
{
	int		i;
	int		j;

	j = 0;
	mlx->map->map_enemy = malloc(sizeof(char *) * (mlx->map->height + 1));
	if (!mlx->map->map_enemy)
		show_error(mlx, MALLOC_ERROR);
	while (mlx->map->map_tab[j])
	{
		i = -1;
		mlx->map->map_enemy[j] = malloc(sizeof(char) * (mlx->map->width + 1));
		if (!mlx->map->map_enemy[j])
		{
			clear_map(mlx->map->map_enemy, j);
			show_error(mlx, MALLOC_ERROR);
		}
		while (mlx->map->map_tab[j][++i])
		{
			if (mlx->map->map_tab[j][i] == '1')
				mlx->map->map_enemy[j][i] = '1';
			else if (mlx->map->map_tab[j][i] == 'B')
				mlx->map->map_enemy[j][i] = 'B';
			else
				mlx->map->map_enemy[j][i] = '0';
		}
		mlx->map->map_enemy[j][i] = '\0';
		j++;
	}
	mlx->map->map_enemy[j] = NULL;
}

static void move_enemy(t_minilx *mlx, int x, int y)
{
	printf("%s\n", "move enemy start");
	ft_put_image(mlx, mlx->sprites->empty->name, x, y);
	mlx->map->map_enemy[y][x] = '0';
	y -= 1;
	mlx->map->map_enemy[y][x] = 'B';
	ft_put_image(mlx, mlx->sprites->empty->name, x, y);
	ft_put_image(mlx, mlx->sprites->enemy->frames[0], x, y);
}

void find_enemy(t_minilx *mlx)
{
	int height;
	int width;

	printf("%s\n", "find enemy start");
	height = 0;
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
}
