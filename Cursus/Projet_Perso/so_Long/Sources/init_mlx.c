/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:29:12 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/30 22:12:56 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void init_map_values(t_minilx *mlx)
{
	mlx->map->collectable_nb = 0;
	mlx->map->exit_nb = 0;
	mlx->map->player_nb = 0;
}

static void secure_all_img(t_minilx *mlx, int param)
{
	if (param == 1)
	{
		mlx->sprites->collectable = NULL;
		mlx->sprites->empty = NULL;
		mlx->sprites->exit = NULL;
		mlx->sprites->player = NULL;
		mlx->sprites->wall = NULL;
	}
	else if (param == 2)
	{
		mlx->sprites->collectable->name = NULL;
		mlx->sprites->empty->name = NULL;
		mlx->sprites->exit->name = NULL;
		mlx->sprites->player->name = NULL;
		mlx->sprites->wall->name = NULL;
	}
}

static void	allocate_struct(t_minilx *mlx)
{
	mlx->sprites = malloc(sizeof(t_sprite));
	if (!mlx->sprites)
		show_error(mlx, MALLOC_ERROR);
	secure_all_img(mlx, 1);
	mlx->sprites->empty = malloc(sizeof(t_img));
	if (!mlx->sprites->empty)
		show_error(mlx, MALLOC_ERROR);
	mlx->sprites->wall = malloc(sizeof(t_img));
	if (!mlx->sprites->wall)
		show_error(mlx, MALLOC_ERROR);
	mlx->sprites->player = malloc(sizeof(t_img));
	if (!mlx->sprites->player)
		show_error(mlx, MALLOC_ERROR);
	mlx->sprites->exit = malloc(sizeof(t_img));
	if (!mlx->sprites->exit)
		show_error(mlx, MALLOC_ERROR);
	mlx->sprites->collectable = malloc(sizeof(t_img));
	if (!mlx->sprites->collectable)
		show_error(mlx, MALLOC_ERROR);
	secure_all_img(mlx, 2);
	mlx->map = malloc(sizeof(t_map));
	if (!mlx->map)
		show_error(mlx, MALLOC_ERROR);
	init_map_values(mlx);
}

void	init_minilx(t_minilx *mlx)
{
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->sprites = NULL;
	mlx->map = NULL;
	allocate_struct(mlx);
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		show_error(mlx, SERVER_X);
	mlx->movement = 0;
	mlx->screen_size_x = SCREEN_SIZE_X;
	mlx->screen_size_y = SCREEN_SIZE_Y;
}
