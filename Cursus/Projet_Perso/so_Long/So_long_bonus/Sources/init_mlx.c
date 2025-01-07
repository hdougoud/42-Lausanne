/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:29:12 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/07 12:04:53 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void init_map_values(t_minilx *mlx)
{
	mlx->map->collectable_nb = 0;
	mlx->map->exit_nb = 0;
	mlx->map->player_nb = 0;
}

static void	secure_all_image(t_minilx *mlx)
{
	mlx->sprites->player->frames[0] = NULL;
	mlx->sprites->player->frames[1] = NULL;
	mlx->sprites->player->frames[2] = NULL;
	mlx->sprites->player->frames[3] = NULL;
	mlx->sprites->player->frames[4] = NULL;
	mlx->sprites->player->frames[5] = NULL;
	mlx->sprites->player->frames[6] = NULL;
	mlx->sprites->player->frames[7] = NULL;
	mlx->sprites->chest->frames[0] = NULL;
	mlx->sprites->chest->frames[1] = NULL;
	mlx->sprites->chest->frames[2] = NULL;
	mlx->sprites->chest->frames[3] = NULL;
	mlx->sprites->empty->name = NULL;
	mlx->sprites->exit->name = NULL;
	mlx->sprites->wall->name = NULL;
}

static void secure_struct(t_minilx *mlx)
{
	mlx->sprites->chest = NULL;
	mlx->sprites->empty = NULL;
	mlx->sprites->exit = NULL;
	mlx->sprites->player = NULL;
	mlx->sprites->wall = NULL;
}

static void	allocate_struct(t_minilx *mlx)
{
	mlx->sprites = malloc(sizeof(t_sprite));
	if (!mlx->sprites)
		show_error(mlx, MALLOC_ERROR);
	secure_all_struct(mlx);
	mlx->sprites->empty = malloc(sizeof(t_img));
	if (!mlx->sprites->empty)
		show_error(mlx, MALLOC_ERROR);
	mlx->sprites->wall = malloc(sizeof(t_img));
	if (!mlx->sprites->wall)
		show_error(mlx, MALLOC_ERROR);
	mlx->sprites->player = malloc(sizeof(t_player));
	if (!mlx->sprites->player)
		show_error(mlx, MALLOC_ERROR);
	mlx->sprites->exit = malloc(sizeof(t_img));
	if (!mlx->sprites->exit)
		show_error(mlx, MALLOC_ERROR);
	mlx->sprites->chest = malloc(sizeof(t_chest));
	if (!mlx->sprites->chest)
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
	mlx->map->map_tab = NULL;
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		show_error(mlx, SERVER_X);
	mlx->movement = 0;
	mlx->screen_size_x = SCREEN_SIZE_X;
	mlx->screen_size_y = SCREEN_SIZE_Y;
}
