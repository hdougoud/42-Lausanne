/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:45:31 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/23 14:22:26 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void destroy_image(t_minilx *mlx)
{
	if (mlx->sprites->collectable)
		mlx_destroy_image(mlx->mlx, mlx->sprites->collectable->name);
	if (mlx->sprites->empty)
		mlx_destroy_image(mlx->mlx, mlx->sprites->empty->name);
	if (mlx->sprites->exit)
		mlx_destroy_image(mlx->mlx, mlx->sprites->exit->name);
	if (mlx->sprites->player)
		mlx_destroy_image(mlx->mlx, mlx->sprites->player->name);
	if (mlx->sprites->wall)
		mlx_destroy_image(mlx->mlx, mlx->sprites->wall->name);
}

static void free_struct(t_minilx *mlx)
{
	if (mlx->sprites)
	{
		if (mlx->sprites->collectable)
			free(mlx->sprites->collectable);
		if(mlx->sprites->empty)
			free(mlx->sprites->empty);
		if(mlx->sprites->exit)
			free(mlx->sprites->exit);
		if(mlx->sprites->player)
			free(mlx->sprites->player);
		if(mlx->sprites->wall)
			free(mlx->sprites->wall);
		free(mlx->sprites);
	}
}

void	quit_properly(t_minilx *mlx)
{
	int i;

	destroy_image(mlx);
	free_struct(mlx);
    if (mlx->map)
    {
	    i = 0;
        while (mlx->map[i])
            free(mlx->map[i++]);
        free(mlx->map);
	}
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
}