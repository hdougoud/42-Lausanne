/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:40:14 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/18 18:55:18 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
#define SO_LONG

#include "libft/libft.h"
#include <errno.h>
#include <mlx.h>

typedef struct s_minilx
{
	void	*mlx;
	void	*win;
	int		win_x;
	int		win_y;
	void	*img;
	int		img_weight;
	int		img_height;
}			t_minilix;

#endif