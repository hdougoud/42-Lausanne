/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:34:51 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/18 23:11:20 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int read_map(int map)
{
	int value;
	char c;
	
	if (read(map, &c, 1) == 0)
		return (-1);
	if (c == '1')
		return (1);
	return (0);
}

int main(void)
{
	int			i;
	int			map;
	int			readed;
	t_minilix	mlx;
	
	i = 0;
	readed = 1;
	mlx.win_x = 0;
	mlx.win_y = 0;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx,300 , 250, "so_long"); //TODO: COMPTER LA TAILLE DE LA FENETRE
	mlx.img = mlx_png_file_to_image(mlx.mlx, "sprites/mini_boxe.png", &mlx.img_weight, &mlx.img_height);
	map = open("maps/map_test.ber", O_RDONLY);
	if (map == -1)
		perror("Can't open map");
	while(readed > 0)
	{
		readed = read_map(map);
		printf("%d\n", readed);
		if (readed == 1)
			mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, mlx.win_x, mlx.win_y);
		mlx.win_x += 50;
		if (mlx.win_x == 350)
		{
			mlx.win_y += 50;
			mlx.win_x = 0;
		}
	}
	mlx_loop(mlx.mlx);
}
