/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:06:12 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/09 17:04:25 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	chest_animation(t_minilx *mlx)
{
	int	chest_x;
	int	chest_y;

	chest_x = mlx->sprites->chest->posx;
	chest_y = mlx->sprites->chest->posy;
	ft_put_image(mlx, mlx->sprites->empty->name, chest_x, chest_y);
	ft_put_image(mlx, mlx->sprites->chest->frames
	[mlx->sprites->chest->current_frame], chest_x, chest_y);
	if (mlx->sprites->chest->current_frame >= 3)
	{
		mlx->sprites->chest->current_frame = 0;
		mlx->sprites->chest->is_animating = 0;
	}
	mlx->sprites->chest->current_frame++;
}

void	put_previous_layer(t_minilx *mlx)
{
	int	x;
	int	y;

	x = mlx->player_pos_x;
	y = mlx->player_pos_y;
	ft_put_image(mlx, mlx->sprites->empty->name, x, y);
	if (mlx->map->map_tab[mlx->player_pos_y][mlx->player_pos_x] == 'C')
		ft_put_image(mlx, mlx->sprites->chest->frames[0], x, y);
	if (mlx->sprites->chest->is_animating == 0)
	{
		if (mlx->map->map_tab[mlx->player_pos_y][mlx->player_pos_x] == 'O')
			ft_put_image(mlx, mlx->sprites->chest->frames[3], x, y);
	}
	
	else if (mlx->sprites->chest->is_animating)
	if (mlx->map->map_tab[mlx->player_pos_y][mlx->player_pos_x] == 'E')
		ft_put_image(mlx, mlx->sprites->exit->name, x, y);
}

int	next_frame(t_minilx *mlx)
{
	mlx->frame_count++;
	if (mlx->frame_count >= 1500)
	{
		put_previous_layer(mlx);
		if (mlx->sprites->chest->is_animating == 1)
			chest_animation(mlx);
		ft_put_image(mlx, mlx->sprites->player->frames
		[mlx->sprites->player->current_frame],
			mlx->player_pos_x, mlx->player_pos_y);
		if (mlx->sprites->player->current_frame >= 7)
			mlx->sprites->player->current_frame = 0;
		mlx->frame_count = 0;
		mlx->sprites->player->current_frame++;
	}
	
	return (0);
}
