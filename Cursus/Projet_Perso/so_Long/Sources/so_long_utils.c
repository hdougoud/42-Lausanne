/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:56:02 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/22 22:54:44 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	quit_properly(t_minilx *mlx)
{
	safe_free((void *) &mlx->sprites->collectable);
	safe_free((void *) &mlx->sprites->empty);
	safe_free((void *) &mlx->sprites->exit);
	safe_free((void *) &mlx->sprites->player);
	safe_free((void *) &mlx->sprites->wall);
	safe_free((void *) &mlx->sprites);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
} 

void	ft_put_image(t_minilx *mlx, t_img *img, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->name,
	x * TEXTURE_SIZE, y * TEXTURE_SIZE);
}

void	init_mlx(t_minilx *mlx)
{
	mlx->sprites = malloc(sizeof(t_sprite));	//TODO : PROTECT MALLOC
	mlx->sprites->empty = malloc(sizeof(t_img));
	mlx->sprites->wall = malloc(sizeof(t_img));
	mlx->sprites->player = malloc(sizeof(t_img));
	mlx->sprites->exit = malloc(sizeof(t_img));
	mlx->sprites->collectable = malloc(sizeof(t_img));
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		show_error(SERVER_X);
	mlx->win = mlx_new_window(mlx->mlx, (mlx->map_width * TEXTURE_SIZE),
			(mlx->map_height * TEXTURE_SIZE), "so_long");
	if (!mlx->win)
		show_error(WINDOW_ERROR);
}

char	*strdup_map_line(const char *str)
{
	int		i;
	int		str_len;
	char	*ptr;

	i = 0;
	str_len = ft_strlen(str);
	if (str[str_len - 1] == '\n')
		str_len -= 1;
	ptr = malloc(sizeof(char) * (str_len) + 1);
	if (!ptr)
		show_error(MALLOC_ERROR);
	while (i < str_len)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
