/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:40:14 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/23 21:47:11 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <errno.h>
# include <mlx.h>

# define SPRITE "sprites/XPM"
# define TEXTURE_SIZE 64

/*----------------------------------Keycode----------------------------------*/

# define ESC	53
# define E		14
# define W		13
# define A		0
# define S		1
# define D		2

/*-----------------------------------Error-----------------------------------*/

# define MALLOC_ERROR		0
# define CANNOT_OPEN_FILE	1
# define WRONG_ARGUMENTS	2
# define WRONG_EXT			3
# define WRONG_MAP_SIZE		4
# define SERVER_X			5
# define WINDOW_ERROR		6
# define BAD_CHAR			7
# define TOO_MUCH_EXIT		8
# define TOO_MUCH_PLAYER	9
# define UNDER_COLLECIBLE	10
# define WRONG_MAP_PATERN	11

/*-----------------------------------Struct----------------------------------*/

typedef struct s_img
{
	void	*name;
	int		x;
	int		y;
}			t_img;

typedef struct s_sprite
{
	t_img	*player;
	t_img	*collectable;
	t_img	*exit;
	t_img	*wall;
	t_img	*empty;
}			t_sprite;

typedef struct s_map
{
	char	**map_tab;
	int		height;
	int		width;
	int		exit;
	int		player;
	int		collectable;
}			t_map;

typedef struct s_minilx
{
	void		*mlx;
	void		*win;
	t_sprite	*sprites;
	t_map		*map;
	int			player_pos_x;
	int			player_pos_y;
	int			movement;
}				t_minilx;

int	hook_keyboard(int keycode, t_minilx *mlx);

void	init_minilx(t_minilx *mlx);
void	file_to_image(t_minilx *mlx);
void	check_path_map(t_minilx *mlx);
void	init_map(t_minilx *mlx, char *map_name);
void	show_error(t_minilx *mlx, int error_nb);
void	quit_properly(t_minilx *mlx, int exit_status);
void	ft_put_image(t_minilx *mlx, t_img *img, int width, int height);

char	*strdup_map_line(t_minilx *mlx, char *str);

#endif