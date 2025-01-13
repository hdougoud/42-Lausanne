/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:06:12 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/13 01:31:36 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void player_dash(t_minilx *mlx)
{
	int	img_x;

	img_x = mlx->sprites->player->dsh_current_frame + 1;
	if (mlx->sprites->player->dsh_current_frame >= 7)
	{
		mlx->player_pos_x += 1;
		mlx->sprites->player->dash = 0;
		mlx->sprites->player->dsh_current_frame = 0;
		return ;
	}
	if (mlx->map->map_tab[mlx->player_pos_y][mlx->player_pos_x + 1] == '1')
	{
		mlx->sprites->player->dash = 0;
		return ;
	}
	if (mlx->map->map_enemy[mlx->player_pos_y][mlx->player_pos_x + 1] == 'B')
		mlx->map->map_enemy[mlx->player_pos_y][mlx->player_pos_x + 1] = '0';
	put_previous_layer(mlx, mlx->player_pos_x, mlx->player_pos_y);
	put_previous_layer(mlx, mlx->player_pos_x + 1, mlx->player_pos_y);
	find_enemy(mlx, 2);
	mlx_put_image_to_window(mlx->mlx, mlx->win, 
		mlx->sprites->player->dsh_frames[img_x - 1],
		(mlx->player_pos_x * TEXTURE_SIZE) + (img_x * 8),
		mlx->player_pos_y * TEXTURE_SIZE);
	mlx->sprites->player->dsh_current_frame++;
}

static void	player_idle(t_minilx *mlx)
{
	ft_put_image(mlx, mlx->sprites->player->frames
	[mlx->sprites->player->current_frame],
		mlx->player_pos_x, mlx->player_pos_y);
	if (mlx->delayed_frame >= 2)
	{
		if (mlx->sprites->player->current_frame >= 7)
			mlx->sprites->player->current_frame = 0;
		mlx->sprites->player->current_frame++;
		mlx->delayed_frame = 0;
	}
}

static void	chest_animation(t_minilx *mlx)
{
	int	chest_x;
	int	chest_y;

	chest_x = mlx->sprites->chest->posx;
	chest_y = mlx->sprites->chest->posy;
		ft_put_floor(mlx, chest_x, chest_y);
	ft_put_image(mlx, mlx->sprites->chest->frames
	[mlx->sprites->chest->current_frame], chest_x, chest_y);
	if (mlx->sprites->chest->current_frame >= 3)
	{
		mlx->sprites->chest->current_frame = 0;
		mlx->sprites->chest->is_animating = 0;
	}
	mlx->sprites->chest->current_frame++;
}

void	next_enemy_frame(t_minilx *mlx, int x, int y)
{
	int frame;

	frame = mlx->sprites->enemy->current_frame;
	put_previous_layer(mlx, x, y);
	ft_put_image(mlx, mlx->sprites->enemy->frames[frame], x, y);
	if (mlx->sprites->enemy->current_frame >= 4)
		mlx->sprites->enemy->current_frame = 0;
	mlx->sprites->enemy->current_frame++;
}

void	put_previous_layer(t_minilx *mlx, int x, int y)
{
	ft_put_floor(mlx, x, y);
	if (mlx->map->map_tab[y][x] == 'C')
		ft_put_image(mlx, mlx->sprites->chest->frames[0], x, y);
	if (mlx->sprites->chest->is_animating == 0)
	{
		if (mlx->map->map_tab[y][x] == 'O')
			ft_put_image(mlx, mlx->sprites->chest->frames[3], x, y);
	}
	else if (mlx->sprites->chest->is_animating == 1)
	{
		ft_put_image(mlx, mlx->sprites->chest->frames
		[mlx->sprites->chest->current_frame],
		mlx->sprites->chest->posx, mlx->sprites->chest->posy);
	}
	if (mlx->map->map_tab[y][x] == 'E')
		ft_put_image(mlx, mlx->sprites->exit->name, x, y);
	if (mlx->map->map_enemy[y][x] == 'D')
		ft_put_image(mlx, mlx->sprites->enemy->dth_frames[5], x, y);
}

int	next_frame(t_minilx *mlx)
{
	mlx->frame_count++;
	if (mlx->frame_count >= mlx->frames_rates)
	{
		check_player_life(mlx);
		put_previous_layer(mlx, mlx->player_pos_x, mlx->player_pos_y);
		find_enemy(mlx, 2);
		if (mlx->sprites->enemy->delayed_frame >= 12 && mlx->sprites->player->dash == 0)
		{		
			find_enemy(mlx, 1);
			if (mlx->map->map_enemy[mlx->player_pos_y][mlx->player_pos_x] == 'B')
				mlx->sprites->player->life -= 1;
			mlx->sprites->enemy->delayed_frame = 0;
		}
		if (mlx->sprites->chest->is_animating == 1)
			chest_animation(mlx);
		if (mlx->sprites->player->life <= 0)
			player_death(mlx);
		else if (mlx->sprites->player->dash == 1)
			player_dash(mlx);
		else
			player_idle(mlx);
		mlx->sprites->enemy->delayed_frame++;
		mlx->delayed_frame++;
		mlx->frame_count = 0;
	}
	return (0);
}
