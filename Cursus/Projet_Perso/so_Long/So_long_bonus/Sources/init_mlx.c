/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:29:12 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/09 13:58:18 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void init_values(t_minilx *mlx)
{
	mlx->map->collectable_nb = 0;
	mlx->map->exit_nb = 0;
	mlx->map->player_nb = 0;
	mlx->movement = 0;
	mlx->frame_count = 0;
	mlx->sprites->enemy->current_frame = 0;
	mlx->sprites->chest->is_animating = 0;
	mlx->sprites->chest->current_frame = 0;
	mlx->sprites->player->current_frame = 0;
	mlx->sprites->player->life = 3;
	mlx->screen_size_x = SCREEN_SIZE_X;
	mlx->screen_size_y = SCREEN_SIZE_Y;
}

static void	secure_all_img(t_minilx *mlx)
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
	mlx->sprites->enemy->frames[0] = NULL;
	mlx->sprites->enemy->frames[1] = NULL;
	mlx->sprites->enemy->frames[2] = NULL;
	mlx->sprites->enemy->frames[3] = NULL;
	mlx->sprites->enemy->frames[4] = NULL;
	mlx->sprites->heart->frames[0] = NULL;
	mlx->sprites->heart->frames[1] = NULL;
	mlx->sprites->heart->frames[2] = NULL;
	mlx->sprites->empty->name = NULL;
	mlx->sprites->exit->name = NULL;
	mlx->sprites->wall->name = NULL;
}

static void secure_all_struct(t_minilx *mlx)
{
	mlx->sprites->player = NULL;
	mlx->sprites->chest = NULL;
	mlx->sprites->empty = NULL;
	mlx->sprites->exit = NULL;
	mlx->sprites->wall = NULL;
	mlx->sprites->enemy = NULL;
}

static void	allocate_struct(t_minilx *mlx)
{
	mlx->sprites = malloc(sizeof(t_sprite));
	if (!mlx->sprites)
		show_error(mlx, MALLOC_ERROR);
	secure_all_struct(mlx);
	mlx->sprites->player = malloc(sizeof(t_player));
	if (!mlx->sprites->player)
		show_error(mlx, MALLOC_ERROR);
	mlx->sprites->chest = malloc(sizeof(t_chest));
	if (!mlx->sprites->chest)
		show_error(mlx, MALLOC_ERROR);
	mlx->sprites->empty = malloc(sizeof(t_img));
	if (!mlx->sprites->empty)
		show_error(mlx, MALLOC_ERROR);
	mlx->sprites->wall = malloc(sizeof(t_img));
	if (!mlx->sprites->wall)
		show_error(mlx, MALLOC_ERROR);
	mlx->sprites->exit = malloc(sizeof(t_img));
	if (!mlx->sprites->exit)
		show_error(mlx, MALLOC_ERROR);
	mlx->sprites->enemy = malloc(sizeof(t_enemy));
	if (!mlx->sprites->enemy)
		show_error(mlx, MALLOC_ERROR);
	mlx->sprites->heart = malloc(sizeof(t_heart));
	if (!mlx->sprites->heart)
		show_error(mlx, MALLOC_ERROR);
	secure_all_img(mlx);
	mlx->map = malloc(sizeof(t_map));
	if (!mlx->map)
		show_error(mlx, MALLOC_ERROR);
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
	init_values(mlx);
}
