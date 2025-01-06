/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:13:02 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/06 11:29:59 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void clear_copy_map(t_minilx *mlx, char **map, int j)
{
	while(j >= 0)
	{
		free(map[j]);
		j--;
	}
	show_error(mlx, MALLOC_ERROR);
}

static char	**copy_map(t_minilx *mlx)
{
	int		i;
	int		j;
	char	**map;

	j = 0;
	map = malloc(sizeof(char *) * mlx->map->height);
	if (!map)
		show_error(mlx, MALLOC_ERROR);
	while (mlx->map->map_tab[j])
	{
		i = 0;
		map[j] = malloc(sizeof(char) * mlx->map->width);
		if (!map)
			clear_copy_map(mlx, map, j);
		while (mlx->map->map_tab[j][i])
		{
			map[j][i] = mlx->map->map_tab[j][i];
			i++;
		}
		map[j][i] = '\0';
		j++;
	}
	map[j] = NULL;
	return (map);
}

static void check_map_border(t_minilx *mlx)
{
	int	x;
	int	y;

	x = 0;
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

void	path_is_valide(char **map, int *collectable, int *exit, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
			return ;
	if (map[y][x] == 'C')
		(*collectable)++;
	if (map[y][x] == 'E')
		(*exit)++;
	map[y][x] = 'V';
	path_is_valide(map, collectable, exit, x + 1, y);
	path_is_valide(map, collectable, exit, x, y + 1);
	path_is_valide(map, collectable, exit, x - 1, y);
	path_is_valide(map, collectable, exit, x, y - 1);
}

void	check_path_map(t_minilx *mlx)
{
	
	int exit;
	int collectable;
	char **map;
	
	check_map_border(mlx);
	collectable = 0;
	exit = 0;
	map = copy_map(mlx);
	path_is_valide(map, &collectable, &exit, mlx->player_pos_x, mlx->player_pos_y);
	if (exit != mlx->map->exit_nb || collectable != mlx->map->collectable_nb)
		show_error(mlx, WRONG_MAP_PATH);
}

// ADD VERIF FOR ENEMY