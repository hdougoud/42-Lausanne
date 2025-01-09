/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:40:14 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/09 16:55:50 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <errno.h>
# include <time.h>
# include <mlx.h>

# define TEXTURE_SIZE		64
# define MAX_EXIT			1
# define MAX_PLAYER			1
# define MIN_COLLECTABLE	1
# define SCREEN_SIZE_X		5120
# define SCREEN_SIZE_Y		2880
# define MAX_RAND				3
/*----------------------------------Keycode----------------------------------*/

# define ESC				53
# define E					14
# define W					13
# define A					0
# define S					1
# define D					2

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
# define WINDOWS_TOO_BIG	12
# define EXIT_NOT_REACH		13
# define C_NOT_REACH		14

/*-----------------------------------Struct----------------------------------*/

typedef struct s_img
{
	void	*name;
	int		x;
	int		y;
}			t_img;

typedef struct s_chest
{
	void	*frames[4];
	int		current_frame;
	int		is_animating;
	int		posx;
	int		posy;
	int		x;
	int		y;
}			t_chest;

typedef struct s_player
{
	void	*frames[8];
	void	*dth_frames[8];
	int		current_frame;
	int		dth_current_frame;
	int		life;
	int		x;
	int		y;
}			t_player;

typedef struct s_enemy
{
	void			*frames[5];
	int				current_frame;
	int				x;
	int				y;
}					t_enemy;

typedef struct s_heart
{
	void	*frames[3];
	int		current_frame;
	int		x;
	int		y;
}			t_heart;

typedef struct s_sprite
{
	t_img		*exit;
	t_img		*wall;
	t_img		*empty;
	t_chest		*chest;
	t_enemy		*enemy;
	t_heart		*heart;
	t_player	*player;
}				t_sprite;

typedef struct s_map
{
	char	**map_tab;
	char	**map_enemy;
	char	**map_enemy_copy;
	int		height;
	int		width;
	int		exit_nb;
	int		player_nb;
	int		collectable_nb;
}			t_map;

typedef struct s_minilx
{
	void		*mlx;
	void		*win;
	t_sprite	*sprites;
	t_map		*map;
	int			player_pos_x;
	int			player_pos_y;
	int			screen_size_x;
	int			screen_size_y;
	int			movement;
	int			frame_count;
}				t_minilx;

/*----------------------------------Functions--------------------------------*/

int		next_frame(t_minilx *mlx);
int		windows_closed(t_minilx *mlx);
int		hook_keyboard(int keycode, t_minilx *mlx);

void	find_enemy(t_minilx *mlx);
void	init_minilx(t_minilx *mlx);
void	clear_map(char **map, int j);
void	file_to_image(t_minilx *mlx);
void	check_path_map(t_minilx *mlx);
void	load_player_image(t_minilx *mlx);
void	check_player_life(t_minilx *mlx);
void	put_previous_layer(t_minilx *mlx);
void	init_map(t_minilx *mlx, char *map_name);
void	show_error(t_minilx *mlx, int error_nb);
void	quit_properly(t_minilx *mlx, int exit_status);
void	ft_put_image(t_minilx *mlx, t_img *img, int width, int height);

char	*strdup_map_line(t_minilx *mlx, char *str);
char	**create_enemy_map(t_minilx *mlx, char **map);

#endif