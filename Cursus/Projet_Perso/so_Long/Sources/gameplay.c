/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:21:41 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/22 02:19:32 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int check_movement(int keycode, t_minilx *mlx)
{
	if (keycode == W)
	{
		if (mlx->map[mlx->player_pos_y - 1][mlx->player_pos_x] == '1')
			return (1);
	}
	if (keycode == S)
	{
		if (mlx->map[mlx->player_pos_y + 1][mlx->player_pos_x] == '1')
			return (1);
	}
	if (keycode == A)
	{
		if (mlx->map[mlx->player_pos_y][mlx->player_pos_x - 1] == '1')
			return (1);
	}
	if (keycode == D)
	{
		if (mlx->map[mlx->player_pos_y][mlx->player_pos_x + 1] == '1')
			return (1);
	}
	return (0);
}

void move_player(int keycode, t_minilx *mlx)
{
	if (check_movement(keycode, mlx) == 1)
		return ;
	ft_put_image(mlx, mlx->sprites->empty,
		mlx->player_pos_x, mlx->player_pos_y);
	if (mlx->map[mlx->player_pos_y][mlx->player_pos_x] == 'E')
		ft_put_image(mlx, mlx->sprites->exit, mlx->player_pos_x, mlx->player_pos_y);
	if (keycode == W)
		mlx->player_pos_y -= 1;
	else if (keycode == S)
		mlx->player_pos_y += 1;
	else if (keycode == A)
		mlx->player_pos_x -= 1;
	else if (keycode == D)
		mlx->player_pos_x += 1;
	ft_put_image(mlx, mlx->sprites->player,
	mlx->player_pos_x, mlx->player_pos_y);
	ft_printf("%d\n", ++mlx->mouvement);
}

int	hook_keyboard(int keycode, t_minilx *mlx)
{
	if (keycode == ESC)
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
		move_player(keycode, mlx);
	else if (keycode == E)
	{
		if (mlx->map[mlx->player_pos_y][mlx->player_pos_x] == 'E')
			exit(EXIT_SUCCESS);
	}
	return (0);
}
