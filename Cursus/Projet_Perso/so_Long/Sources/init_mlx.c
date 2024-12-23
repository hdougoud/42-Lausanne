/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:29:12 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/23 18:49:51 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void init_map_values(t_minilx *mlx)
{
	mlx->map->collectable = 0;
	mlx->map->max_exit = 1;
	mlx->map->max_player = 1;
}

static void secure_all_img(t_minilx *mlx)
{
	mlx->sprites->collectable = NULL;
	mlx->sprites->empty = NULL;
	mlx->sprites->exit = NULL;
	mlx->sprites->player = NULL;
	mlx->sprites->wall = NULL;
}

static void	allocate_struct(t_minilx *mlx)
{
	mlx->sprites = malloc(sizeof(t_sprite));
	if (!mlx->sprites)
		show_error(MALLOC_ERROR);
	secure_all_img(mlx);
	mlx->sprites->empty = malloc(sizeof(t_img));
	if (!mlx->sprites->empty)
		show_error(MALLOC_ERROR);
	mlx->sprites->wall = malloc(sizeof(t_img));
	if (!mlx->sprites->wall)
		show_error(MALLOC_ERROR);
	mlx->sprites->player = malloc(sizeof(t_img));
	if (!mlx->sprites->player)
		show_error(MALLOC_ERROR);
	mlx->sprites->exit = malloc(sizeof(t_img));
	if (!mlx->sprites->exit)
		show_error(MALLOC_ERROR);
	mlx->sprites->collectable = malloc(sizeof(t_img));
	if (!mlx->sprites->collectable)
		show_error(MALLOC_ERROR);
	mlx->map = malloc(sizeof(t_map));
	if (!mlx->map)
		show_error(MALLOC_ERROR);
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
		show_error(SERVER_X);
	mlx->movement = 0;
}
