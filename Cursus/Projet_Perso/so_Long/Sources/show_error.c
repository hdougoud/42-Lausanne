/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:33:10 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/23 18:58:12 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_error(t_minilx *mlx, int error_nb)
{
	ft_putendl_fd(COLOR_RED "Error", 2);
	if (error_nb == MALLOC_ERROR)
		perror(COLOR_RED "Malloc failed");
	else if (error_nb == CANNOT_OPEN_FILE)
		perror(COLOR_YELLOW "Can't open file");
	else if (error_nb == WRONG_ARGUMENTS)
		ft_printf(COLOR_YELLOW "wrong number of agrument, please selecte one map");
	else if (error_nb == WRONG_EXT)
		ft_printf(COLOR_YELLOW "wrong extension, this program can only read .ber files");
	else if (error_nb == WRONG_MAP_SIZE)
		ft_printf(COLOR_YELLOW "wrong map size : map need to be a rectangle");
	else if (error_nb == SERVER_X)
		perror(COLOR_RED "can't link to X server");
	else if (error_nb == WINDOW_ERROR)
		perror(COLOR_RED "can't create windows");
	else if (error_nb == BAD_CHAR)
		ft_printf(COLOR_YELLOW "invalid map: character not recognized on the map file");
	//TODO : ADD COLORS
	//TODO : CLOSE AND FREE ALL
	//TODO : SEPARETE CRITICAL ERROR AND SIMPLE ERROR AND CHANGE DE ERROR COLOR IN FUCNTION
	quit_properly(mlx, EXIT_FAILURE);
}
