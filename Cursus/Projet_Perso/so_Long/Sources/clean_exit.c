/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:45:31 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/23 19:24:43 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void destroy_image(t_minilx *mlx)
{
	if (mlx->sprites->collectable->name)
		mlx_destroy_image(mlx->mlx, mlx->sprites->collectable->name);
	if (mlx->sprites->empty->name)
		mlx_destroy_image(mlx->mlx, mlx->sprites->empty->name);
	if (mlx->sprites->exit->name)
		mlx_destroy_image(mlx->mlx, mlx->sprites->exit->name);
	if (mlx->sprites->player->name)
		mlx_destroy_image(mlx->mlx, mlx->sprites->player->name);
	if (mlx->sprites->wall->name)
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
		free(mlx->map);
	}
}

void	quit_properly(t_minilx *mlx, int exit_status)
{
	int i;
	
	if (mlx->mlx && mlx->sprites)
		destroy_image(mlx);
    if (mlx->map && mlx->map->map_tab)
    {
	    i = 0;
        while (mlx->map->map_tab[i])
            free(mlx->map->map_tab[i++]);
        free(mlx->map->map_tab);
	}
	free_struct(mlx);
	if (mlx->mlx && mlx->win)
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		mlx_destroy_window(mlx->mlx, mlx->win);
	}
	exit(exit_status);
}
