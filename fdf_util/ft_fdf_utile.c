/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_utile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:26:27 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/02/28 21:16:01 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

t_Matrix	ft_do_t_matrix(int x, int y, int z, int color)
{
	t_Matrix	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.color = color;
	return (point);
}

t_len_map	ft_do_t_len_map(int x, int y, int z_max, int z_min)
{
	t_len_map	point;

	point.x = x;
	point.y = y;
	point.z_max = z_max;
	point.z_min = z_min;
	return (point);
}

int	abs_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

t_point	ft_matrix_mult(t_Matrix matrix, t_settings len_win)
{
	t_point	point;

	point.x = len_win.zoom * ((cos((len_win.angel_x * 3.14) / 180) * \
			(double)matrix.x) + (-sin((len_win.angel_y * 3.14) / 180) * \
			((double)matrix.y)));
	point.y = len_win.zoom * ((sin((len_win.angel_x * 3.14) / 180) * \
			((double)matrix.x)) + (cos((len_win.angel_y * 3.14) / 180) * \
			((double) matrix.y))) + (-((len_win.depth) * (double)matrix.z));
	point.x += len_win.start_x;
	point.y /= 2;
	point.color = matrix.color;
	return (point);
}
