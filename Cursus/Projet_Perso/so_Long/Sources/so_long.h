/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:40:14 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/21 22:23:36 by hdougoud         ###   ########.fr       */
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
# define W		13
# define A		0
# define S		1
# define D		2

/*-----------------------------------Error-----------------------------------*/

void	show_error(int error_nb);

# define MALLOC_ERROR		0
# define CANNOT_OPEN_FILE	1
# define WRONG_ARGUMENTS	2
# define WRONG_EXT			3
# define WRONG_MAP_SIZE		4
# define SERVER_X			5
# define WINDOW_ERROR		6
# define BAD_CHAR			7

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

typedef struct s_minilx
{
	void		*mlx;
	void		*win;
	int			win_x;
	int			win_y;
	t_sprite	*sprites;
	char		**map;
	int			map_height;
	int			map_width;
}				t_minilx;

int	moveplayer(int keycode, t_minilx *mlx);

void	init_mlx(t_minilx *mlx);
void	file_to_image(t_minilx *mlx);
void	init_mlx_and_map(t_minilx *mlx, char *map_name);
void	ft_put_image(t_minilx *mlx, t_img *img, int width, int height);

char	*strdup_map_line(const char *s1);

#endif