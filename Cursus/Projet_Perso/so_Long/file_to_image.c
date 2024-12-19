/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:15:22 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/19 10:50:34 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void file_to_image(t_minilx *mlx)
{
	mlx->wall_img = mlx_png_file_to_image(mlx->mlx, "sprites/mini_boxe.png", &mlx->wimg_weight, &mlx->wimg_height);
	if (!mlx->wall_img)
		perror("Cannot assigned file");
	mlx->empt_img = mlx_png_file_to_image(mlx->mlx, "sprites/pixel_sand.png", &mlx->eimg_weight, &mlx->eimg_height);
	if (!mlx->wall_img)
		perror("Cannot assigned file");
}
