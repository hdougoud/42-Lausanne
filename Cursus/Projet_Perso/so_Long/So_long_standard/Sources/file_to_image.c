/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:15:22 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/06 15:42:41 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	files_to_image_2(t_minilx *mlx);

void	file_to_image(t_minilx *mlx)
{
	mlx->sprites->empty->name = mlx_xpm_file_to_image(mlx->mlx,
			"sprites/XPM/wood.xpm",
			&mlx->sprites->empty->x,
			&mlx->sprites->empty->y);
	if (!mlx->sprites->empty->name)
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->wall->name = mlx_xpm_file_to_image(mlx->mlx,
			"sprites/XPM/boxe.xpm",
			&mlx->sprites->wall->x,
			&mlx->sprites->wall->y);
	if (!mlx->sprites->wall->name)
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->player->name = mlx_xpm_file_to_image(mlx->mlx,
			"sprites/XPM/player.xpm",
			&mlx->sprites->player->x,
			&mlx->sprites->player->y);
	if (!mlx->sprites->player->name)
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->exit->name = mlx_xpm_file_to_image(mlx->mlx,
			"sprites/XPM/exit.xpm",
			&mlx->sprites->exit->x,
			&mlx->sprites->exit->y);
	if (!mlx->sprites->exit->name)
		show_error(mlx, CANNOT_OPEN_FILE);
	files_to_image_2(mlx);
}

void	files_to_image_2(t_minilx *mlx)
{
	mlx->sprites->collectable->name = mlx_xpm_file_to_image(mlx->mlx,
			"sprites/XPM/collectable.xpm",
			&mlx->sprites->collectable->x,
			&mlx->sprites->collectable->y);
	if (!mlx->sprites->collectable->name)
		show_error(mlx, CANNOT_OPEN_FILE);
}