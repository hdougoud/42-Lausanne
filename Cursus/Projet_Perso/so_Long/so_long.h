/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:40:14 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/19 12:05:41 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
#define SO_LONG

#include "libft/libft.h"
#include <errno.h>
#include <mlx.h>

/*-----------------------------------Error-----------------------------------*/

void	show_error(int error_nb);

# define wrong_arguments 2
# define wrong_ext 3

typedef struct s_minilx
{
	void	*mlx;
	void	*win;
	int		win_x;
	int		win_y;
	void	*wall_img;
	int		wimg_weight;
	int		wimg_height;
	void	*empt_img;
	int		eimg_weight;
	int		eimg_height;
}			t_minilx;

void	file_to_image(t_minilx *mlx);
void	init_map(t_minilx *mlx, char *map_name);

#endif