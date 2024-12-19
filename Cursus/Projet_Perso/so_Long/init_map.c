/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:01:26 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/19 16:13:06 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	validate_map(t_minilx *mlx)
{
	int	height;
	int	map_line_len;

	height = 0;
	map_line_len = ft_strlen(mlx->map[0]);
	while(mlx->map[height])
	{
		printf("%s\n", mlx->map[height]);
		height++;
	}
	printf("%d\n", map_line_len);
}

static void	convert_map_tab(t_minilx *mlx, char *map_name, int map_height)
{
	int		fd;
	int		height;
	int		map_line_len;
	char	*map_line;

	height = 0;
	mlx->map = malloc(sizeof(char) * (map_height + 1));
	fd = open(map_name, O_RDONLY);
	if(fd == -1)
		show_error(cannot_open_file);
	while(1)
	{
		map_line = get_next_line(fd);
		if (map_line == NULL)
			break ;
		map_line_len = (ft_strlen(map_line) - 1);
		mlx->map[height] = malloc(sizeof(char) * (map_line_len + 1));
		if(!mlx->map[height])
			show_error(malloc_error);
		ft_strlcpy(mlx->map[height], map_line, map_line_len);
		height++;
		free(map_line);
	}
	mlx->map[height] = NULL;
	close(fd);
}

void	init_map(t_minilx *mlx, char *map_name)
{
	int		fd;
	char	*ext;
	int		map_height;
	char	*line;
	
	map_height = 0;
	ext = ft_strnstr(map_name, ".ber", ft_strlen(map_name));
	if (ext == NULL)
		show_error(wrong_ext);
	if (ft_strncmp(ext, ".ber", 5) != 0)
		show_error(wrong_ext);
	fd = open(map_name, O_RDONLY);
	if(fd == -1)
		show_error(-1);
	while(get_next_line(fd))
		map_height++;
	printf("%d\n", map_height);
	convert_map_tab(mlx, map_name, map_height);
	close (fd);
	validate_map(mlx);
}
