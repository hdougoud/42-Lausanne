/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:06:12 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/10 18:46:32 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_idle(t_minilx *mlx)
{
	ft_put_image(mlx, mlx->sprites->player->frames
	[mlx->sprites->player->current_frame],
		mlx->player_pos_x, mlx->player_pos_y);
	if (mlx->delayed_frame >= 1)
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
}

int	next_frame(t_minilx *mlx)
{	
	int death_frame;

	mlx->frame_count++;
	if (mlx->frame_count >= mlx->frames_rates)
	{
		check_player_life(mlx);
		put_previous_layer(mlx, mlx->player_pos_x, mlx->player_pos_y);
		if (mlx->sprites->chest->is_animating == 1)
			chest_animation(mlx);
		find_enemy(mlx, 2);
		if (mlx->sprites->player->life > 0)
			player_idle(mlx);
		else
			player_death(mlx);
		mlx->frame_count = 0;
		mlx->delayed_frame++;
	}
	return (0);
}
