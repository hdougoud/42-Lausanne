/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:01:26 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/20 17:13:00 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_tab(t_minilx *mlx)
{
	int height;

	height = 0;
	while(mlx->map[height])
	{
		printf("%s\n", mlx->map[height]);
		height++;
	}
}


static void show_map(t_minilx *mlx)
{
	int height;
	int	width;

	height = 0;
	init_mlx(mlx);
	file_to_image(mlx);
	while(mlx->map[height])
	{
		width = 0;
		while (mlx->map[height][width + 1])
		{
			if (mlx->map[height][width] == '0')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->sprites->empty->name,
				height * TEXTURE_SIZE, width * TEXTURE_SIZE);
			}
			else if (mlx->map[height][width + 1] == '1')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->sprites->wall->name,
				height * TEXTURE_SIZE, width * TEXTURE_SIZE);
			}
			width++;
		}
		height++;
	}
}	

static void	validate_map_size(t_minilx *mlx)
{
	int	height;
	int	map_line_len;

	height = 1;
	map_line_len = ft_strlen(mlx->map[0]);
	while (mlx->map[height])
	{
		if (map_line_len != ft_strlen(mlx->map[height]))
			show_error(WRONG_MAP_SIZE);
		height++;
	}
	mlx->map_width = map_line_len;
	mlx->map_height = height;   //POSSIBLE ERREUR ICI DE LONGEUR/LARGEUR
	//AJOUTER LA PRISE EN CHARGE DE CARACTERE NON DEFINIT
	//ET STOPPER LE CHECK ICI
	
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
	if (fd == -1)
		show_error(CANNOT_OPEN_FILE);
	while (1)
	{
		map_line = get_next_line(fd);
		if (map_line == NULL)
			break ;
		map_line_len = (ft_strlen(map_line));
		mlx->map[height] = malloc(sizeof(char) * (map_line_len + 1));
		if (!mlx->map[height])
			show_error(MALLOC_ERROR);
		mlx->map[height] = strdup_map_line(map_line);
		height++;
		free(map_line);
	}
	mlx->map[height] = NULL;
	print_tab(mlx);
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
