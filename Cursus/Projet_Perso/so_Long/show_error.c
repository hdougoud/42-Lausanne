/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:33:10 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/19 15:57:44 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_error(int error_nb)
{
	if (error_nb == -1)
		perror("Can't open file");
	else if (error_nb == 0)
		perror("Malloc error");
	else if (error_nb == 2)
		ft_printf("wrong number of agrument, please selecte one map");
	else if (error_nb == 3)
		ft_printf("wrong extension, this program can only read .ber files");
	exit(EXIT_FAILURE);
}
