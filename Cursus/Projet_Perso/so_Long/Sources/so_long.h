/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:40:14 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/20 11:53:40 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
#define SO_LONG

#include "../libft/libft.h"
#include <errno.h>
#include <mlx.h>

/*-----------------------------------Error-----------------------------------*/

#define sprite "sprites/XPM"

void	show_error(int error_nb);

# define malloc_error 0
# define cannot_open_file 1
# define wrong_arguments 2
# define wrong_ext 3
# define wrong_map_size 4
# define server_x 5
# define window_error 6

typedef struct s_sprite
{
	void		*wall;
	int			wall_x;
	int			wall_y;
	void		*empty;
	int			empty_x;
	int			empty_y;
}				t_sprite;

typedef struct s_minilx
{
	void		*mlx;
	void		*win;
	int			win_x;
	int			win_y;
	t_sprite	img;
	char		**map;
	int			map_height;
	int			map_width;
}				t_minilx;

void			file_to_image(t_minilx *mlx);
void			init_map(t_minilx *mlx, char *map_name);

char			*strdup_map_line(const char *s1);

#endif