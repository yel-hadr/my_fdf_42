/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:12:48 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/02/28 20:26:15 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static void	do_len(t_point *len, t_len_map end, t_settings *map)
{
	len[0] = ft_matrix_mult(ft_do_t_matrix(end.x - 1, end.y - 1, \
			end.z_max, 0xFFFFF), *map);
	len[1] = ft_matrix_mult(ft_do_t_matrix(end.x - 1, 0, \
			end.z_max, 0xFFFFF), *map);
	len[2] = ft_matrix_mult(ft_do_t_matrix(0, end.y - 1, \
			end.z_min, 0xFFFFF), *map);
}

t_settings	*ft_len_of_win(t_len_map end)
{
	t_settings	*map;
	t_point		len[3];

	map = ft_calloc(1, sizeof(t_settings));
	if (!map)
		exit (1);
	map->angel_y = -45;
	map->angel_x = -45;
	map->depth = 20;
	map->start_x = 100;
	map->zoom = 20;
	map->len_win.x = 1920;
	map->len_win.y = 1080;
	do_len(len, end, map);
	while (map->zoom > 0 && (abs(len[0].x) + 100 > 1920 || \
			abs(len[1].y) + abs(len[2].y) + 100 > 1080))
	{
		map->zoom--;
		map->depth--;
		do_len(len, end, map);
	}
	map->start = abs(len[1].y) + 100;
	map->len_win.y = abs(len[1].y) + abs(len[2].y) + 200;
	map->len_win.x = abs(len[0].x) + 200;
	return (map);
}
