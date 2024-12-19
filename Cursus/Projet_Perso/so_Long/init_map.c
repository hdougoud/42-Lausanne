/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:01:26 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/19 12:14:15 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_minilx *mlx, char *map_name)
{
	char *ext;
	
	ext = ft_strnstr(map_name, ".ber", ft_strlen(map_name));
	if (ext == NULL)
		show_error(wrong_ext);
	if (ft_strncmp(ext, ".ber", 5) != 0)
		show_error(wrong_ext);
}