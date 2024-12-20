/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:15:22 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/20 16:44:53 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_to_image(t_minilx *mlx)
{
	mlx->sprites->empty->name = mlx_xpm_file_to_image(mlx->mlx,
			"sprites/XPM/sand.xpm",
			&mlx->sprites->empty->x,
			&mlx->sprites->empty->y);
	if (!mlx->sprites->empty->name)
		show_error(CANNOT_OPEN_FILE);
	mlx->sprites->wall->name = mlx_xpm_file_to_image(mlx->mlx,
			"sprites/XPM/boxe.xpm",
			&mlx->sprites->wall->x,
			&mlx->sprites->wall->y);
	if (!mlx->sprites->wall->name)
		show_error(CANNOT_OPEN_FILE);
}
