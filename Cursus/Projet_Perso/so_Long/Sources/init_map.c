/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:01:26 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/21 23:43:42 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	show_map(t_minilx *mlx)
{
	int	height;
	int	width;

	height = 0;
	init_mlx(mlx);
	file_to_image(mlx);
	while (mlx->map[height])
	{
		width = 0;
		while (mlx->map[height][width])
		{
			ft_put_image(mlx, mlx->sprites->empty, width, height);
			if (mlx->map[height][width] == '1')
				ft_put_image(mlx, mlx->sprites->wall, width, height);
			else if (mlx->map[height][width] == 'P')
			{
				ft_put_image(mlx, mlx->sprites->player, width, height);
				mlx->player_pos_x = width;
				mlx->player_pos_y = height;
			}
			else if (mlx->map[height][width] == 'E')
				ft_put_image(mlx, mlx->sprites->exit, width, height);
			width++;
		}
		height++;
	}
}

static void	validate_map_size(t_minilx *mlx)
{
	int width;
	int	height;
	int	map_line_len;

	height = 0;
	map_line_len = ft_strlen(mlx->map[0]);
	while (mlx->map[height])
	{
		width = 0;
		while (mlx->map[height][width])
		{
			if ((mlx->map[height][width] != '0')
					&& (mlx->map[height][width] != '1')
					&& (mlx->map[height][width] != 'E')
					&& (mlx->map[height][width] != 'C')
					&& (mlx->map[height][width] != 'P'))
				show_error(BAD_CHAR);
			width++;
		}
		if (map_line_len != ft_strlen(mlx->map[height]))
			show_error(WRONG_MAP_SIZE);
		height++;
	}
	mlx->map_width = map_line_len;
	mlx->map_height = height;
}

static void	convert_map_tab(t_minilx *mlx, char *map_name, int map_height)
{
	int		fd;
	int		height;
	int		map_line_len;
	char	*map_line;

	height = 0;
	mlx->map = malloc(sizeof(char *) * (map_height + 1));
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		show_error(CANNOT_OPEN_FILE);
	while (1)
	{
		map_line = get_next_line(fd);
		if (map_line == NULL)
			break ;
		mlx->map[height] = strdup_map_line(map_line);
		height++;
		free(map_line);
	}
	mlx->map[height] = NULL;
	close(fd);
}

void	init_mlx_and_map(t_minilx *mlx, char *map_name)
{
	int		fd;
	char	*ext;
	int		map_height;
	char	*line;

	map_height = 0;
	ext = ft_strnstr(map_name, ".ber", ft_strlen(map_name));
	if (ext == NULL)
		show_error(WRONG_EXT);
	if (ft_strncmp(ext, ".ber", 5) != 0)
		show_error(WRONG_EXT);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		show_error(-1);
	while (get_next_line(fd))
		map_height++;
	convert_map_tab(mlx, map_name, map_height);
	close (fd);
	validate_map_size(mlx);
	show_map(mlx);
}
