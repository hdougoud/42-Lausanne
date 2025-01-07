/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:21:41 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/06 10:33:32 by hdougoud         ###   ########.fr       */
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
	ft_put_image(mlx, mlx->sprites->wall, 0, 0);
	ft_put_image(mlx, mlx->sprites->wall, 1, 0);
	mlx_string_put(mlx->mlx, mlx->win, 16, 16, 0xFFFFFF, string);
	ft_printf("%d\n", mlx->movement);
	free(mouv);
	free(string);
}

static int check_movement(int keycode, t_minilx *mlx)
{
	if (keycode == W)
	{
		if (mlx->map->map_tab[mlx->player_pos_y - 1][mlx->player_pos_x] == '1')
			return (1);
	}
	if (keycode == S)
	{
		if (mlx->map->map_tab[mlx->player_pos_y + 1][mlx->player_pos_x] == '1')
			return (1);
	}
	if (keycode == A)
	{
		if (mlx->map->map_tab[mlx->player_pos_y][mlx->player_pos_x - 1] == '1')
			return (1);
	}
	if (keycode == D)
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
	ft_put_image(mlx, mlx->sprites->empty,
		mlx->player_pos_x, mlx->player_pos_y);
	if (mlx->map->map_tab[mlx->player_pos_y][mlx->player_pos_x] == 'C')
		ft_put_image(mlx, mlx->sprites->collectable, mlx->player_pos_x, mlx->player_pos_y);
	if (mlx->map->map_tab[mlx->player_pos_y][mlx->player_pos_x] == 'E')
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
	count_player_movement(mlx);
}

int	hook_keyboard(int keycode, t_minilx *mlx)
{
	if (keycode == ESC)
		quit_properly(mlx, EXIT_SUCCESS); 
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
		move_player(keycode, mlx);
	else if (keycode == E)
	{
		if (mlx->map->map_tab[mlx->player_pos_y][mlx->player_pos_x] == 'E')
		{
			if (mlx->map->collectable_nb == 0)
				quit_properly(mlx, EXIT_SUCCESS);
			else (ft_printf("you need to collect all the collectibles before you can go out.\n")); //TODO : CHANGE COLLECTIBLE FOR SPRITE NAME
		}
		if (mlx->map->map_tab[mlx->player_pos_y][mlx->player_pos_x] == 'C')
		{
			mlx->map->collectable_nb--;
			ft_put_image(mlx, mlx->sprites->empty, mlx->player_pos_x, mlx->player_pos_y);
			ft_put_image(mlx, mlx->sprites->player, mlx->player_pos_x, mlx->player_pos_y);
			mlx->map->map_tab[mlx->player_pos_y][mlx->player_pos_x] = '0';
		}
			
	}
	return (0);
}

