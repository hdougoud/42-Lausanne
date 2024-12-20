/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:56:02 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/20 17:11:43 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_minilx *mlx)
{
	mlx->sprites = malloc(sizeof(t_sprite));
	mlx->sprites->empty = malloc(sizeof(t_img));
	mlx->sprites->wall = malloc(sizeof(t_img));
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		show_error(SERVER_X);
	mlx->win = mlx_new_window(mlx->mlx, (mlx->map_width * TEXTURE_SIZE),
			(mlx->map_height * TEXTURE_SIZE), "so_long");
	if (!mlx->win)
		show_error(WINDOW_ERROR);
}

char	*strdup_map_line(const char *s1)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!ptr)
		show_error(MALLOC_ERROR);
	while (s1[i])
	{
		if (s1[i] == '\n')
			i++;
		else
		{	
			ptr[i] = s1[i];
			i++;
		}
	}
	ptr[i] = '\0';
	return (ptr);
}
