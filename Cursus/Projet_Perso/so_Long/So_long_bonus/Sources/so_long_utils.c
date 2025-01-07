/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:56:02 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/29 21:58:14 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	windows_closed(t_minilx *mlx)
{
	quit_properly(mlx, EXIT_SUCCESS);
	return (0);
}

void	ft_put_image(t_minilx *mlx, t_img *img, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->name,
	x * TEXTURE_SIZE, y * TEXTURE_SIZE);
}

char	*strdup_map_line(t_minilx *mlx, char *str)
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
		show_error(mlx, MALLOC_ERROR);
	while (i < str_len)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
