/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:21:41 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/13 13:54:00 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void count_player_movement(t_minilx *mlx)
{
	char *mouv;
	char *string;

	mouv = ft_itoa(++mlx->movement);
	if (!mouv)
		show_error(mlx, MALLOC_ERROR);
	string = ft_strjoin(mouv, " moves");
	if (!string)
		show_error(mlx, MALLOC_ERROR);
	ft_put_floor(mlx, 0, 0);
	ft_put_floor(mlx, 1, 0);
	ft_put_image(mlx, mlx->sprites->wall->name, 0, 0);
	ft_put_image(mlx, mlx->sprites->wall->name, 1, 0);
	mlx_string_put(mlx->mlx, mlx->win, 16, 16, 0xFFFFFF, string);
	ft_printf("%d movements\n", mlx->movement);
	free(mouv);
	free(string);
}

static int check_movement(int keycode, t_minilx *mlx)
{
	if (keycode == W || keycode == UP)
	{
		if (mlx->map->map_tab[mlx->player_pos_y - 1][mlx->player_pos_x] == '1')
			return (1);
	}
	if (keycode == S || keycode == DOWN)
	{
		if (mlx->map->map_tab[mlx->player_pos_y + 1][mlx->player_pos_x] == '1')
			return (1);
	}
	if (keycode == A || keycode == LEFT)
	{
		if (mlx->map->map_tab[mlx->player_pos_y][mlx->player_pos_x - 1] == '1')
			return (1);
	}
	if (keycode == D || keycode == RIGHT)
	{
		if (mlx->map->map_tab[mlx->player_pos_y][mlx->player_pos_x + 1] == '1')
			return (1);
	}
	return (0);
}

void move_player(int keycode, t_minilx *mlx)
{
	if (check_movement(keycode, mlx) == 1)
		return ;
	put_previous_layer(mlx, mlx->player_pos_x, mlx->player_pos_y);
	if (keycode == W || keycode == UP)
		mlx->player_pos_y -= 1;
	else if (keycode == S || keycode == DOWN)
		mlx->player_pos_y += 1;
	else if (keycode == A || keycode == LEFT)
		mlx->player_pos_x -= 1;
	else if (keycode == D || keycode == RIGHT)
		mlx->player_pos_x += 1;
	ft_put_image(mlx, mlx->sprites->player->frames[0],
	mlx->player_pos_x, mlx->player_pos_y);
	count_player_movement(mlx);
	if (mlx->map->map_enemy[mlx->player_pos_y][mlx->player_pos_x] == 'B')
		mlx->sprites->player->life -= 1;
}

int	hook_keyboard(int keycode, t_minilx *mlx)
{
	if (keycode == ESC)
		quit_properly(mlx, EXIT_SUCCESS);
	else if (mlx->sprites->player->life == 0 || mlx->sprites->player->dash == 1)
		return (0);
	else if ((keycode == W || keycode == A || keycode == S || keycode == D)
			|| (keycode <= UP  && keycode >= LEFT))
		move_player(keycode, mlx);
	else if (keycode == E)
	{
		if (mlx->map->map_tab[mlx->player_pos_y][mlx->player_pos_x] == 'E')
		{
			if (mlx->map->collectable_nb == 0)
				quit_properly(mlx, EXIT_SUCCESS);
		}
		if (mlx->map->map_tab[mlx->player_pos_y][mlx->player_pos_x] == 'C' 
				|| mlx->map->map_tab[mlx->player_pos_y][mlx->player_pos_x - 1] == 'C')
			open_chest(mlx);
	}
	else if (keycode == SPACE && mlx->sprites->player->dash == 0)
	{
		mlx->sprites->player->dash = 1;
		count_player_movement(mlx);
	}
	return (0);
}

