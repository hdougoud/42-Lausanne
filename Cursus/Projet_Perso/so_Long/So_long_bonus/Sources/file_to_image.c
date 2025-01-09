/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:15:22 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/09 14:56:06 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void load_heart_image(t_minilx *mlx)
{
	mlx->sprites->heart->frames[0] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Heart/Heart_1.xpm",
			&mlx->sprites->heart->x, &mlx->sprites->heart->y);
	if (!mlx->sprites->heart->frames[0])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->heart->frames[1] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Heart/Heart_2.xpm",
			&mlx->sprites->heart->x, &mlx->sprites->heart->y);
	if (!mlx->sprites->heart->frames[1])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->heart->frames[2] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Heart/Heart_3.xpm",
			&mlx->sprites->heart->x, &mlx->sprites->heart->y);
	if (!mlx->sprites->heart->frames[2])
		show_error(mlx, CANNOT_OPEN_FILE);

}

static void	load_enemy_image(t_minilx *mlx)
{
	mlx->sprites->enemy->frames[0] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Slime/Slime_1.xpm",
			&mlx->sprites->enemy->x, &mlx->sprites->enemy->y);
	if (!mlx->sprites->enemy->frames[0])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->enemy->frames[1] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Slime/Slime_2.xpm",
			&mlx->sprites->enemy->x, &mlx->sprites->enemy->y);
	if (!mlx->sprites->enemy->frames[1])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->enemy->frames[2] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Slime/Slime_3.xpm",
			&mlx->sprites->enemy->x, &mlx->sprites->enemy->y);
	if (!mlx->sprites->enemy->frames[2])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->enemy->frames[3] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Slime/Slime_4.xpm",
			&mlx->sprites->enemy->x, &mlx->sprites->enemy->y);
	if (!mlx->sprites->enemy->frames[3])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->enemy->frames[4] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Slime/Slime_5.xpm",
			&mlx->sprites->enemy->x, &mlx->sprites->enemy->y);
	if (!mlx->sprites->enemy->frames[4])
		show_error(mlx, CANNOT_OPEN_FILE);
}


static void	load_collectable_image(t_minilx *mlx)
{
	mlx->sprites->chest->frames[0] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Chest/Chest_1.xpm",
			&mlx->sprites->chest->x, &mlx->sprites->chest->y);
	if (!mlx->sprites->chest->frames[0])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->chest->frames[1] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Chest/Chest_2.xpm",
			&mlx->sprites->chest->x, &mlx->sprites->chest->y);
	if (!mlx->sprites->chest->frames[1])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->chest->frames[2] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Chest/Chest_3.xpm",
			&mlx->sprites->chest->x, &mlx->sprites->chest->y);
	if (!mlx->sprites->chest->frames[2])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->chest->frames[3] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Chest/Chest_4.xpm",
			&mlx->sprites->chest->x, &mlx->sprites->chest->y);
	if (!mlx->sprites->chest->frames[3])
		show_error(mlx, CANNOT_OPEN_FILE);
}

void	file_to_image(t_minilx *mlx)
{
	mlx->sprites->empty->name = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/wood.xpm",
			&mlx->sprites->empty->x, &mlx->sprites->empty->y);
	if (!mlx->sprites->empty->name)
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->wall->name = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Tree.xpm",
			&mlx->sprites->wall->x, &mlx->sprites->wall->y);
	if (!mlx->sprites->wall->name)
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->exit->name = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/exit.xpm",
			&mlx->sprites->exit->x, &mlx->sprites->exit->y);
	if (!mlx->sprites->exit->name)
		show_error(mlx, CANNOT_OPEN_FILE);
	load_player_image(mlx);
	load_collectable_image(mlx);
	load_enemy_image(mlx);
	load_heart_image(mlx);
}
