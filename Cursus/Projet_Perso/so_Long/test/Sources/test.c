/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:08:09 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/23 15:02:48 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../../libft/libft.h"

typedef struct	s_minilx {
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int 	limx;
	int		limy;
	int		color;
	int		img_width;
	int		img_height;
}				t_minilx;

void pixel_put(t_minilx *minilx)
{
	if (minilx->color == 0xFFFFFF)
		minilx->color = 0xFF0000;
	else 
		minilx->color = 0xFFFFFF;
	while (minilx->y < minilx->limy)
	{
		while(minilx->x < minilx->limx)
		{
			mlx_pixel_put(minilx->mlx, minilx->win, minilx->x, minilx->y, minilx->color);
			minilx->x++;
		}
		minilx->y++;
		minilx->x = minilx->limx - 50;
	}
	minilx->y = minilx->y - 50;
	minilx->limx += 50;
	if (minilx->limx == 550)
	{
		minilx->limx = 0;
		minilx->limy += 50;
	}
}

int	closes(int key, t_minilx *minilx)
{
	if (key == 53)
	{
		mlx_clear_window(minilx->mlx, minilx->win);
		mlx_destroy_window(minilx->mlx, minilx->win);
		exit(EXIT_SUCCESS);
	}
	if (key == 8)
	{
		minilx->x = 0;
		minilx->y = 0;
		minilx->limx = 50;
		minilx->limy = 50;
		if (minilx->color == 0xFFFFFF)
			minilx->color = 0xFF0000;
		else 
			minilx->color = 0xFFFFFF;
	}
	while (minilx->y < 500)
	{
		pixel_put(minilx);	
	}
	return (0);
}

int	main(void)
{
	t_minilx	minilx;
	void		*mlx_img;

	minilx.color = 0xFFFFFF;
	minilx.mlx = mlx_init();
	minilx.win = mlx_new_window(minilx.mlx, 500, 500, "Hello world!");
	mlx_key_hook(minilx.win, closes, &minilx);
	mlx_loop(minilx.mlx);
}