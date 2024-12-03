/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:35:53 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/03 17:51:39 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *add_str(char *str, char *format, int *str_i)
{
	int i;

	i = 0;
	while (format[i])
		str[*str_i++] = format[i++];
	return (str); //TODO : CONVERT i TO A POINTER INT
}