/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:13:02 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/23 18:12:22 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO : BFS (Breadth-First Search)
#include "so_long.h"

void	check_path_map(t_minilx *mlx)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	mlx->map->collectable = 1;
	printf("hauteur %d\n", mlx->map->width);
	printf("hauteur %d\n", mlx->map->height);
}